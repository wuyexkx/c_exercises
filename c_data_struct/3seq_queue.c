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
    // 满了就扩增容量 x 2
    if (sq->isfull(sq)) {
        data* newqueue = (data*)malloc(2 * sq->capacity * sizeof(data));        
        if (sq->tail > sq->head)    // not wrap 没有环绕，直接拷贝，无需更改head tail
            memcpy(newqueue, sq->queue, (sq->capacity) * sizeof(data));
        else {                      // wrap  环绕了, 先拷贝后面的，再拷贝前面的，最后修改head tail
            int len_back = sq->size - sq->head + 1;
            memcpy(newqueue, sq->queue + sq->head, len_back * sizeof(data));
            int len_front = sq->tail + 1;
            memcpy(newqueue + len_front, sq->queue, len_front * sizeof(data));
            sq->head = 0;       // 修改head tail
            sq->tail = sq->size;// 
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
    // else {
    //     printf("sequence queue isempty.\n");
    //     exit(1);
    // }
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
#define DATASIZE    (20)

    // 准备数据
    data dat[DATASIZE];
    for (int i=0; i<DATASIZE; ++i) dat[i].d = i;

    // 创建循环顺序链表
    sq_queue sq = sq_create(CAPACITY);

    for (int i=0; i<DATASIZE; ++i) {
        sq.pop(&sq);
        sq.push(&sq, dat[i]);
    }
    printf("1 size:%d   only one:%d\n", sq.size, sq.front(&sq).d); // 1 实际只存了一个
    sq.pop(&sq);

    // 再次放入数据
    for (int i=0; i<DATASIZE; ++i) {
        sq.push(&sq, dat[i]);
    }

    printf("2 size:%d  ", sq.size);                                  // 2 存放了DATASIZE个
    // 取完打印
    while (!sq.isempty(&sq)) {
        printf("%d ", sq.front(&sq).d);
        sq.pop(&sq);
    }
    printf("\n3 size:%d\n", sq.size);                               // 3 空了

    sq_destory(&sq);
    
// stdout:
    // 1 size:1   only one:19
    // 2 size:20  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
    // 3 size:0  
    return 0;
}