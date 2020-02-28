// 用于生成具体函数的宏
// 在外部需要宏定义TEMPLATE
#ifndef TEMPLATE
#error "not define 'TEMPLATE'"
#else
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc realloc
#include <string.h>     // memcpy
#include <assert.h>     // assert

// 重要的3行代码，最终完成T_type 如 int_stack
// ---------------------------------------------------------
#define ___(type,T)  T##_##type             // int_stack 
#define __(type,T)  ___(type,T)             
#define _(type)     __(type,TEMPLATE)       // TEMPLATE_type
// 以下两行是函数名和初始化
#define $(funcname) __(funcname,functype)   // functype_funcname
#define init(x)     __(init,x)()            // x_init()
// ---------------------------------------------------------


// 简单的实现栈
typedef struct _(stack) _(stack);   // int_stack
struct _(stack){
    int top;
    int elmt_size;
    size_t stack_length;
    TEMPLATE *stack;
    void (*push)(_(stack) *s, TEMPLATE *data);
    TEMPLATE (*pop)(_(stack) *s);
    int (*empty)(_(stack) *s);
    void (*free)(_(stack) *s);
};

#define functype    _(stack)
#define stack(x)    x##_##stack 
#define _str(x) #x
#define STRING(x)  _str(x)

void $(push)(_(stack) *s, TEMPLATE *p_data)
{
    if(s->top == s->stack_length){
        s->stack_length *= 2;
        s->stack = realloc(s->stack, s->stack_length);
        assert(s->stack != NULL);
    }
    char *target = (char *)s->stack + s->top * s->elmt_size;
    memcpy(target, p_data, s->elmt_size);
    ++s->top;
}

TEMPLATE $(pop)(_(stack) *s)
{
    TEMPLATE data;
    if(!$(empty)(s)){
        char *source = (char *)s->stack + --s->top * s->elmt_size;
        memcpy(&data, source, s->elmt_size);
        return data;
    }
    else{
        printf(STRING(_(stack)));
        printf(" is empty!\n");
        // assert(0);
    }
}

int $(empty)(_(stack) *s)
{
    if(s->top == 0)
        return 1;
    else
        return 0;
}

void $(free)(_(stack) *s)
{
    free(s->stack);
}

_(stack) $(init)()
{
    _(stack) s;
    s.top = 0;
    s.stack_length = 2;
    s.elmt_size = sizeof(TEMPLATE);
    s.stack = (TEMPLATE *)malloc(sizeof(TEMPLATE) * s.elmt_size);
    assert(s.stack != NULL);
    s.pop = $(pop);
    s.push = $(push);
    s.empty = $(empty);
    s.free = $(free);

    return s;
}

#undef TEMPLATE
#endif
