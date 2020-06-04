#if 0
CC="gcc"
filename="$0"
name="${filename%.*}"
$CC -o $name $filename
$name $@
rm $name
exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int d;
} data;
typedef struct seq_queue sq_queue;
struct seq_queue{
    data* queue;
    int head;
    int tail;
    int size;
    int capacity;
    int (*isempty)(sq_queue*);
    int (*isfull)(sq_queue*);
    void (*push)(sq_queue*, data);
    void (*pop)(sq_queue*);
    data (*front)(sq_queue*);
    data (*rear)(sq_queue*);

};

int sq_isempty(sq_queue* sq)
{ return (sq->head == sq->tail); }
int sq_isfull(sq_queue* sq)
{ return ((sq->tail + 1) % sq->capacity == sq->head); }
data sq_front(sq_queue* sq)
{
    if (!sq->isempty(sq)) {
        int h = (sq->head + 1) % sq->capacity;
        return sq->queue[h];
    }
}
data sq_rear(sq_queue* sq)
{
    if (!sq->isempty(sq))
        return sq->queue[sq->tail];
}
void sq_push(sq_queue* sq, data d)
{
    // 满了就扩增容量
    if (sq->isfull(sq)) {
        data* newqueue = (data*)malloc(2 * sq->capacity * sizeof(data));        
        if (sq->tail > sq->head)    // not wrap 没有环绕，直接拷贝，无需更改head tail
            memcpy(newqueue, sq->queue, (sq->capacity) * sizeof(data));
        else {                      // wrap  环绕了, 先拷贝后面的，再拷贝前面的，最后修改head tail
            int len1 = sq->size - sq->head + 1;
            memcpy(newqueue, sq->queue + sq->head, len1 * sizeof(data));
            int len2 = sq->tail + 1;
            memcpy(newqueue + len1, sq->queue, len2 * sizeof(data));
            sq->head = 0;
            sq->tail = sq->size;
        }
        sq->capacity *= 2;
        free(sq->queue);            
        sq->queue = newqueue;
    }
    sq->tail = (sq->tail + 1) % sq->capacity; 
    sq->queue[sq->tail] = d;
    sq->size++;
}
void sq_pop(sq_queue* sq)
{
    if (!sq->isempty(sq)) {
        sq->head = (sq->head + 1) % sq->capacity;
        sq->size--;
    }
    else {
        printf("q_queue isempty.\n");
        exit(1);
    }
}
sq_queue sq_create(int capacity)
{
    sq_queue sq;
    sq.head = sq.tail = 0;
    sq.queue    = (data*)malloc((capacity) * sizeof(data));
    sq.size     = 0;
    sq.capacity = capacity;
    sq.isempty  = sq_isempty;
    sq.isfull   = sq_isfull;
    sq.push     = sq_push;
    sq.pop      = sq_pop;
    sq.front    = sq_front;
    sq.rear     = sq_rear;

    return sq;
}
void sq_destory(sq_queue* sq)
{ free(sq->queue); }


int main()
{
#define CAPACITY    (2)    
    
    // 准备数据
    data dat[50];
    for (int i=0; i<50; ++i)
        dat[i].d = i;

    // 创建循环顺序链表
    sq_queue sq = sq_create(CAPACITY);

    sq.push(&sq, dat[4]);
    sq.push(&sq, dat[3]);
    sq.pop(&sq);
    sq.push(&sq, dat[2]);
    sq.push(&sq, dat[1]);
    sq.pop(&sq);
    sq.pop(&sq);
    sq.pop(&sq);

    // 取出打印
    while (!sq.isempty(&sq)) {
        printf("%d ", sq.front(&sq).d);
        sq.pop(&sq);
    }

    printf("\n");

    // 再次放入数据
    for (int i=0; i<10; ++i) {
        sq.push(&sq, dat[i]);
    }

    // 取出打印
    while (!sq.isempty(&sq)) {
        printf("%d ", sq.front(&sq).d);
        sq.pop(&sq);
    }

    for (int i=0; i<CAPACITY; ++i) {
        sq.push(&sq, dat[i]);
    }
    // 取出打印
    while (!sq.isempty(&sq)) {
        printf("%d ", sq.front(&sq).d);
        sq.pop(&sq);
    }

    sq_destory(&sq);
    
    return 0;
}