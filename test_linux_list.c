#include <stdio.h>
#include <stddef.h>

// Linux中的链表
struct list_head{
    struct list_head *next;
    struct list_head *prev;
};
// 一个自定义数据结构，然后将节点放入本数据结构
struct AAA{
    char i;
    long j;
    struct list_head list;
};

// &( (type *)0)->member ) 直接获取member的相对位置
#define offset_of_member(type, member) (size_t)&( ((type *)0)->member )
// 根据 结构体成员指针、结构体类型、成员名称 获取节点的起始地址（简化容易理解）
#define container_of(ptr, type, member) ({ \
    (type *)( (char *)ptr - offset_of_member(type, member) ); \
})
// // 实际实现如下
// #define container_of(ptr, type, member) ({ \
//     const typeof( ((type *)0)->member ) *__mptr = (ptr); \
//     (type *)( (char *)ptr - offset_of_member(type, member) ); \
// })

int main()
{
    // 定义AAA型结构体变量aaa并初始化，aaa也是一个节点
    struct AAA aaa = {
        .i = 127,
        .j = 123456789,
        .list.next = aaa.list.prev = NULL,
    };
    printf("\naaa.i = %d\naaa.j = %d\n", aaa.i, aaa.j);

    // 查看member的offset
    printf("offset i: %d\n", offset_of_member(struct AAA, i));
    printf("offset j: %d\n", offset_of_member(struct AAA, j));
    printf("offset p: %d\n", offset_of_member(struct AAA, list));
    printf("offset p1: %d\n", offset_of_member(struct AAA, list.next));
    printf("offset p2: %d\n", offset_of_member(struct AAA, list.prev));
    
    // 直接查看节点aaa的起始地址
    printf("\nobs_aaa1_addr: %p\n", &aaa);
    // 通过container_of间接获取节点aaa的起始地址
    printf("obs_aaa2_addr: %p\n", container_of(&aaa.i, struct AAA, i));
    printf("obs_aaa3_addr: %p\n", container_of(&aaa.j, struct AAA, j));
    printf("obs_aaa4_addr: %p\n", container_of(&aaa.list, struct AAA, list));
    printf("obs_aaa5_addr: %p\n", container_of(&aaa.list.next, struct AAA, list.next));
    printf("obs_aaa6_addr: %p\n", container_of(&aaa.list.prev, struct AAA, list.prev));

    return 0;
}