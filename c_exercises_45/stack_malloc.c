#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include "stack.h"

/*
用于释放用户自己的数据空间，这里只是读出了存放的指针值
*/
void freefn_strs(const stack *s, void *elmt_addr)
{
    // 取出数据
    char *p_data;
    memcpy(&p_data, elmt_addr, s->elmt_size);
    // // 释放
    // free(p_data);
}

int main()
{
    /*---------------1. 存放int型数据-----------------*/
    // 定义stack结构体变量
    stack bd_stack;
    // 初始化这个stack，stack元素大小、非分配无需free用户数据
    stack_new(&bd_stack, sizeof(int), NULL);

    // 入栈100个int
    for(int i=0; i<10; ++i){
        stack_push(&bd_stack, &i);
    }
    // 再入栈100个int
    for(int i=0; i<15; ++i){
        stack_push(&bd_stack, &i);
    }
    // 弹出
    int temp;
    while(!stack_empty(&bd_stack)){
        stack_pop(&bd_stack, &temp);
        printf("%d ", temp);
    }
    // 输出分配的长度
    printf("\n%d\n", bd_stack.alloc_length);
    stack_free(&bd_stack);
    /*---------------------------------------------------------*/ 


    /*----------------2. 存放指针数据------------------*/ 
    #define MAX_NAME_SIZE   (9 + 1)
    // 准备数据strs，申请内存放字符串，最后需要释放掉这个内存
    char strings[5][10] = {"Kangkang", "Michel", "Jine", "Maria", "Dong"};
    // 申请空间的首地址存放在strs中
    char *strs[5];
    // 动态分配数据需要的字节数，将分配的结果保存在strs中
    for(int i=0; i<5; ++i){
        strs[i] = malloc(sizeof(char) * MAX_NAME_SIZE);
        // strs[i] = strings[i];// 仅仅是指向了同一字符串
        memcpy(strs[i], strings[i], strlen(strings[i])+1);// 拷贝，+1是因为字符串还有'\0'
        // printf("%s %d\n", strs[i], strlen(strs[i]));
    }

    // 定义跟字符串有关的栈
    stack strs_stack;
    // 初始化，存储指针类型，有自定义释放函数
    stack_new(&strs_stack, sizeof(char *), freefn_strs);
    // 压入数据，存放分配内存的首地址
    for(int i=0; i<5; ++i){
        stack_push(&strs_stack, &strs[i]);
        printf("p-%p ", strs[i]); // 申请空间的首地址存放在strs中
    }

    printf("\n");
    // 弹出数据
    char *t;
    while(!stack_empty(&strs_stack)){
        stack_pop(&strs_stack, &t);
        printf("t-%p %s %d\n", t, t, strlen(t)); // 打印弹出的数据
    }
    stack_free(&strs_stack);

    // 释放
    for(int i=0; i<5; ++i){
        free(strs[i]);
    }
    /*---------------------------------------------------------*/ 

    return 0;
}
