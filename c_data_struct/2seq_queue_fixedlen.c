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
    // 扩增容量
    if (sq->isfull(sq)) {
        printf("%d isfull.\n", __LINE__);
        return;
    }

    sq->tail = (sq->tail + 1) % sq->capacity; // 
    sq->queue[sq->tail] = d;
    sq->size++;
}
void sq_pop(sq_queue* sq)
{
    if (!sq->isempty(sq)) {
        sq->head = (sq->head + 1) % sq->capacity;
        sq->size--;
    }
    else 
        printf("%d isempty.\n", __LINE__);
}

sq_queue sq_create(int capacity)
{
    sq_queue sq;
    sq.head = sq.tail = 0;
    sq.queue    = (data*)malloc((capacity + 1) * sizeof(data));
    sq.size     = 0;
    sq.capacity = capacity + 1;
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
#define CAPACITY    (10)    
    
    // 准备数据
    data dat[CAPACITY];
    for (int i=0; i<CAPACITY; ++i)
        dat[i].d = i;

    // 创建循环顺序链表
    sq_queue sq = sq_create(CAPACITY);
    // 放满数据
    for (int i=0; i<CAPACITY; ++i) {
        sq.push(&sq, dat[i]);
    }
    // 取出前5
    sq.pop(&sq);
    sq.pop(&sq);
    sq.pop(&sq);
    sq.pop(&sq);
    sq.pop(&sq);
    // 再次放入5个数据
    for (int i=0; i<5; ++i) {
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