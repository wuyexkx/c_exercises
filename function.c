// 函数名是 一段存放代码的地址 的标签
// 三个要素： 函数名 参数 返回值

// 可以把函数的地址存放在数组里（注册），然后通过数组去调用函数（回调）
//  int (*a[5])(int , int); // a[5] 数组， *a[5]存放指针的数组， int (*a[5])(int, int)这个指针的类型是这种函数指针
//      a[0] = func1;       // 赋值
//      a[1] = func2;       // 赋值
//      a[0](1, 3);         // 调用

// 参数
//  实参： 调用者 传递的数据
//  形参： 被调者 接收的数据
//  传递形式： 都是拷贝，无论是值传递还是指针传递

// 形参的形式
//  修改某个具体的值：用具体的类型指针指定，如 func(int *, float *, long *, short *)
//  修改一段空间：
//              字符空间 用func(char *)
//              非字符空间 用func(void *) 
// 返回值
//  返回也是拷贝的过程
//  返回两种类型 普通类型和指针（表示一段空间）， 结构体不建议返回
//  从函数内部返回：
                // 1.返回静态区（内部用static修饰）
                // 2.堆区
                // 3.只读常量区 （"hello"） 不常用

#include <stdio.h>

int main()
{
    int (*print1)(const char *, ...); 
    int (*print2)(const char *, ...); 

    print1 = printf;

    print1("print1========\n");
    print1("addr: %p\n", printf);

    print2 = (int (*)(const char *, ...))0x402AB0; // 将printf函数的地址直接取出 然后强制转化
    print2("print2--------\n");

    return 0;
}
