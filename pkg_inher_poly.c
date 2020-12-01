#include <stdio.h>
#include <assert.h>

typedef signed char     int8_t;
typedef unsigned char   uint8_t;
typedef short           int16_t;
typedef unsigned short  uint16_t;
typedef int             int32_t;
typedef unsigned        uint32_t;
typedef float           fp32_t;


struct ShapeVtbl;
typedef struct ShapeVtbl ShapeVtbl;

// -------------------------- 基类为Shape --------------------------
// Shape类似一个抽象类，有指向纯虚函数的虚表指针
typedef struct {
    ShapeVtbl* vptr;    // 虚表指针，用于调用子类的方法
    fp32_t x;
    fp32_t y;
} Shape;
// 虚表结构，存放虚函数指针
struct ShapeVtbl{
    fp32_t (*area)(Shape const* const this);
    void (*draw)(Shape const* const this);
};


static fp32_t Shape_area_(Shape const* const this);
static void Shape_draw_(Shape const* const this);
void Shape_ctor(Shape* const this, fp32_t x, fp32_t y);
void Shape_moveBy(Shape* const this, fp32_t dx, fp32_t dy);
fp32_t Shape_getx(Shape const* const this);
fp32_t Shape_gety(Shape const* const this);
void Shape_ctor(Shape* this, fp32_t x, fp32_t y)
{
    // static保证ShapeVtbl vtbl一直都在，否则通过vptr调用函数时就指错了
    static ShapeVtbl vtbl = {       // 虚表指针初始化，函数中assert
        &Shape_area_,               // Shape类似一个抽象类，有纯虚函数
        &Shape_draw_
    };
    this->vptr = &vtbl;     
    this->x = x;
    this->y = y;
}
static fp32_t Shape_area_(Shape const* const this)
{
    assert(0);  // 类似纯虚函数，但是运行才报错
    return 0U;  // 消除无返回值的警告
}
static void Shape_draw_(Shape const* const this)
{
    assert(0);
}
// 公有方法，根据传递的参数自动调用它的方法
static inline fp32_t Shape_area(Shape const* const this)
{
    return (this->vptr->area)(this);    // 父类方法中调用area函数，
}   
static inline void Shape_draw(Shape const* const this)
{
    this->vptr->draw(this);             // 父类方法中调用draw函数，
}

void Shape_moveBy(Shape* const this, fp32_t dx, fp32_t dy)
{
    this->x += dx;
    this->y += dy;
}
fp32_t Shape_getx(Shape const* const this)
{ return this->x; }
fp32_t Shape_gety(Shape const* const this)
{ return this->y; }


// ------------------------- 一个子类，继承了Shape -------------------------
typedef struct {
    Shape super;    // 继承
    uint16_t width;
    uint16_t height;
} Rectangle;
static fp32_t Rectangle_area_(Shape const * const this);
static void Rectangle_draw_(Shape const * const this);
void Rectangle_ctor(Rectangle* const this, fp32_t x, fp32_t y, uint16_t width, uint16_t height)
{
    // static保证ShapeVtbl vtbl一直都在，否则通过vptr调用函数时就指错了
    static ShapeVtbl vtbl = {       // 构建虚表实例，需要绑定子类对应的函数指针
        &Rectangle_area_,       
        &Rectangle_draw_
    };
    Shape_ctor(&this->super, x, y); // 调用基类的构造函数
    this->super.vptr = &vtbl;       // 绑定，构造函数里为虚指针重新赋值，类似虚函数的重写，父类相当于纯虚函数

    this->height = height;
    this->width = width;
}
// 派生类的函数实现
// 为什么参数类型是Shape*，因为Shape_aera中(this->vptr->area)(this)
static fp32_t Rectangle_area_(Shape const * const this)
{
    // 巧妙，为什么能够根据传入的实例自动调用方法，
    // (this->vptr->area)(this);  --->  vptr -- Rectangle_area_
    Rectangle const* const this_ = (Rectangle const*)this;  
    return (fp32_t)this_->width * (fp32_t)this_->height;
}
static void Rectangle_draw_(Shape const * const this)
{
    Rectangle const* const this_ = (Rectangle const*)this;
    printf("Rectangle_draw_(x=%f,y=%f,width=%f,height=%f)\n", \
            Shape_getx(this), Shape_gety(this), this_->width, this_->height);
}

// ------------------------- 另一个子类，继承了Shape -------------------------
typedef struct {
    Shape super;
    fp32_t radius;
} Circle;
static void Circle_draw_(Shape const* const this);
static fp32_t Circle_area_(Shape const* const this);
void Circle_ctor(Circle* const this, uint16_t x, uint16_t y, fp32_t r)
{
    static ShapeVtbl vtbl = {       // 虚表实例初始化
        &Circle_area_,
        &Circle_draw_,
    };
    Shape_ctor(&this->super, x, y); // 基类构造
    this->super.vptr = &vtbl;       // 虚表指针赋值 
    this->radius = r;               
}
static fp32_t Circle_area_(Shape const* const this)
{
    // 巧妙，为什么能够根据传入的实例自动调用方法，
    // (this->vptr->area)(this);  --->  vptr -- Circle_area_
    const Circle* const t = (Circle*)this; 
    return 3.1416 * t->radius * t->radius;
}
static void Circle_draw_(Shape const* const this)
{ 
    const Circle* const t = (Circle*)this; 
    printf("Circle_draw(), radius=%f\n", t->radius);
}


int main()
{
    // ----------- 基类的实例，假装是抽象类也能有实例 -----------
    Shape ss;
    Shape_ctor(&ss, 1, 2);


    // -------------------- 派生类 1 的实例 -------------------
    Rectangle r1, r2;
    Rectangle_ctor(&r1, 1, 2, 3, 4);
    Rectangle_ctor(&r2, 5, 6, 7, 8);

    printf("%f\n", Shape_area((Shape*)&r1));    // 去除指针类型警告
    // printf("area=%f\n", Shape_area(&ss));    // 运行 Assertion failed!
                                                // Shape的构造函数中的虚指针 所指向的虚表中的 虚函数中 assert

    // -------------------- 派生类 2 的实例 -------------------
    Circle c1;
    Circle_ctor(&c1, 1, 1, 1.414);
    printf("area=%f\n", Shape_area((Shape*)&c1)); 

// OUTPUT:
    // $ gcc -o main test.c && ./main.exe
    // 12.000000
    // area=3.141600

    return 0;
}
