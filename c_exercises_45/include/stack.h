
#ifndef __STACK_H
#define __STACK_H

// 用连续内存空间自定义的栈，malloc实际在虚拟地址上是连续的。

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// // 泛型版本
/*
stack 结构
    @int alloc_length   分配的长度，单位是(elmt_size)
    @int top_index      栈顶的索引
    @void *elements     连续空间的起始地址
    @int elmt_size      元素的大小
    @(*freefn_elmt)(const stack *s, void *elmt_addr) 释放用户自己分配的数据，需要用户自定义，仅仅释放单个元素的空间
*/ 
typedef struct Stack stack; 
struct Stack{
    // 分配的长度，单位是(elmt_size)
    int alloc_length;
    // 栈顶的索引
    int top_index;
    // 连续空间的起始地址
    void *elements;
    // 元素的大小
    int elmt_size;
    // 释放用户自己分配的数据，需要用户自定义，仅仅释放单个元素的空间
    void (*freefn_elmt)(const stack *s, void *elmt_addr);
};

/*
初始化stack
    @stack *s                           结构实体的地址
    @int elmt_size                      单个元素的大小(Byte) 
    @void (*freefn_elmt)(stack *s, void *elmt_addr) 用户自定义用于释放单个元素的函数指针
*/
void stack_new(stack *s, 
                int elmt_size, 
                void (*freefn_elmt)(const stack *s, void *elmt_addr))
{
    // 默认大小为4，单位element_size
    s->alloc_length = 2;
    // 初始化栈顶索引为0
    s->top_index = 0;
    // 单个元素大小
    s->elmt_size = elmt_size;
    // 默认分配
    s->elements = malloc(s->elmt_size * s->alloc_length);
    assert(s->elements != NULL);
    // 赋值函数指针
    s->freefn_elmt = freefn_elmt;
}

/*
入栈
    @stack *s           结构实体的地址
    @void *elem_addr    元素的地址，需要从elem_addr拷贝elem_size数据
*/
void stack_push(stack *s, void *elem_addr)
{
    // 空间增长
    if(s->top_index == s->alloc_length){
        s->alloc_length *= 2;
        s->elements = realloc(s->elements, s->alloc_length * s->elmt_size);
        assert(s->elements != NULL);
    }
    // 赋值，压栈
    // 得到栈顶的指针
    char (*top_ptr) = (char *)s->elements + s->top_index * s->elmt_size;
    // 将元素拷贝到栈顶指针所指空间中去, Des, Src, Size
    memcpy(top_ptr, elem_addr, s->elmt_size);
     ++s->top_index;
}

/*
栈是否为空
    @stack *s  结构实体的地址
    空返回1，不为空返回0
*/
int stack_empty(stack *s)
{
    if(s->top_index == 0)
        return 1;
    else
        return 0;
}

/*
出栈
    @stack *s           stack结构实体的地址
    @void *recv_addr    接收pop元素的指针，需要从栈中拷贝elem_size数据到recv_addr中
*/
void stack_pop(stack *s, void *recv_addr)
{
    // 空的pop报错，阻止运行
    assert(!stack_empty(s));
    // 从栈中获取栈顶地址，然后拷贝到接收地址recv_addr中，最后索引--
    char *source = (char *)s->elements + (s->top_index - 1) * s->elmt_size;
    memcpy(recv_addr, source, s->elmt_size);
    --s->top_index;
}

/* 释放分配的空间
    @stack *s   stack结构实体的地址
    1. 考虑stack申请的elements空间，还有用户存储的数据也可能是分配得到，
    2. 用户的数据如果需要释放，需要自己定义释放函数*/ 
void stack_free(stack *s)
{
    // 先依次释放用户分配的空间，根据用户定义的free函数
    if(s->freefn_elmt != NULL){               // 如果用户定义了并传入了free函数
        for(int i=0; i<s->top_index; ++i){    // 依次释放栈内的数据
            // 以stack的elements为起点，传入数据在stack中的位置 
            s->freefn_elmt(s, (char *)s->elements + i * s->elmt_size);
        }
    }
    // 最后释放stack分配的空间
    free(s->elements); // free释放NULL没有任何作用
    s->elements = NULL;// 上面只是释放内容，ptr的值还在，所以赋值NULL
}


// // 简单版本，int型数据
// struct data{
//     // 指向栈空间
//     int *elements;
//     // 栈顶索引
//     int index_top;
//     // 分配得到的总长度
//     int alloc_length;
// };
// typedef struct data stack;

// void stack_new(stack *s, const int init_lenth)
// {
//     // 初始长度
//     s->alloc_length = 4;
//     // 栈顶指针
//     s->index_top = 0;
//     s->elements = malloc(sizeof(int) * s->alloc_length);
//     //检查地址是否分配成功
//     assert(s->elements != NULL);
// }

// void stack_push(stack *s, const int element)
// {
//     // 检查是否已满，重新分配
//     if(s->index_top == s->alloc_length){
//         s->alloc_length *= 2; 
//         s->elements = realloc(s->elements, sizeof(int) * s->alloc_length);
//         assert(s->elements != NULL);
//     }
//     s->elements[s->index_top++] = element;
// }

// int stack_pop(stack *s)
// {   
//     // 是否为空
//     if(s->index_top == 0){
//         printf("stack is empty.\n");
//         assert(s->index_top == 0);
//     }
//     return s->elements[--s->index_top];
// }

// int stack_empty(stack *s)
// {
//     if(s->index_top == 0)
//         return 1;
//     else
//         return 0;    
// }

// void stack_free(stack *s)
// {
//     free(s->elements);
// }

#endif
