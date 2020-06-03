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

int sq_isempy(sq_queue* sq)
{ return (sq->head == sq->tail); }
int sq_isfull(sq_queue* sq)
{ return ((sq->tail + 1) % sq->capacity == sq->head); }
data sq_front(sq_queue* sq)
{
    if (!sq->isempty(sq))
        return sq->queue[sq->head + 1];
}
data sq_rear(sq_queue* sq)
{
    if (!sq->isempty(sq))
        return sq->queue[sq->tail];
}
void sq_push(sq_queue* sq, data d)
{
    // 扩增容量
    if (sq->isfull(sq)) 
        ;

    sq->tail = (sq->tail + 1) % sq->capacity; // 
    sq->queue[sq->tail] = d;
    sq->size++;
}
void pop(sq_queue* sq)
{
    sq->head = (sq->head + 1) % sq->capacity;
}

sq_queue sq_create(int capacity)
{
    sq_queue sq;
    sq.head = sq.tail = 0;
    sq.queue    = (data*)malloc(capacity * sizeof(data));
    sq.size     = 0;
    sq.capacity = capacity;
    sq.isempty  = sq_isempy;
    sq.isfull   = sq_isfull;
    sq.push     = sq_push;
    // sq.pop      = sq_pop;
    sq.front    = sq_front;
    sq.rear     = sq_rear;

    return sq;
}
void sq_destory(sq_queue* sq)
{ free(sq->queue); }


int main()
{
    data dat[10];
    for (int i=0; i<10; ++i)
        dat[i].d = i;

    sq_queue sq = sq_create(2);
    
    for (int i=0; i<4; ++i)
        sq.push(&sq, dat[i]);
    

    while (!sq.isempty(&sq)) {
        printf("%d ", sq.front(&sq).d);
        sq.pop(&sq);
    }

    // printf("size:%d  isempty:%d  isfull:%d\n", sq.size, sq.isempty(&sq), sq.isfull(&sq));

    sq_destory(&sq);
    return 0;
}