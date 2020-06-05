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
#include <string.h>

// 环形缓冲区 log_buf
#define BUF_SIZE (5)
#define DATA_TYPE char

/* 环形顺序缓存区
@BUF_SIZE    需要自定义两个宏 缓存区大小
@DATA_TYPE   存储数据的类型

@.head = 0,
@.tail = 0,
@.size = 0,
@.capacity = BUF_SIZE   */
typedef struct ring_buf ring_buf;
struct ring_buf{
    DATA_TYPE buf[BUF_SIZE];
    int head;
    int tail;
    int size;
    int capacity;
    int (*isempty)(ring_buf* rb);
    void (*put)(ring_buf* rb, DATA_TYPE c);    
    int (*gets)(ring_buf* rb, DATA_TYPE* dst,  int len);
};
/* 往环形缓存区存入数据
@ring_buf* rb 需要处理的环形缓存区 通常为THIS
@DATA_TYPE c  需要存入的数据    */ 
static void ring_buf_put(ring_buf* rb, DATA_TYPE c)
{
    rb->tail = (rb->tail + 1) % rb->capacity;
    if (rb->head == rb->tail) {  // 满了就覆盖
        rb->head = (rb->head + 1) % rb->capacity;
        rb->size = rb->capacity;
    }
    else rb->size++;               
    rb->buf[rb->tail] = c;
}
/* 检查环形缓存区是否为空
@ring_buf* rb 需要处理的环形缓存区 通常为THIS    */ 
static int ring_buf_isempty(ring_buf* rb)
{ return rb->head == rb->tail; } 
/* 从环形缓存区中获取数据
@ring_buf* rb   需要处理的环形缓存区 通常为THIS 
@DATA_TYPE* dst 存入目标
@int len        获取的数据的个数    
return: 成功复制到dst的数据个数 */
static int ring_buf_gets(ring_buf* rb, DATA_TYPE* dst, int len)
{
    // 缓存区为空
    if (rb->isempty(rb)) return 0;

    // 实际能复制的长度
    int cp_len = len > rb->size ? rb->size : len;
    // 将数据复制到dst，检查是否wrap
    if (rb->tail > rb->head)        // not wrap
        memcpy(dst, rb->buf + 1, cp_len * sizeof(DATA_TYPE));
    else {                          // wrap
        int len_back, len_front;    // 后部分 前部分的长度
        len_back = rb->capacity - rb->head;
        if (cp_len <= len_back)     // 需要的数据长度 <= 后半部的长度 直接复制需要的长度即可
            memcpy(dst, rb->buf + rb->head, cp_len * sizeof(DATA_TYPE));
        else {                      // 需要的数据长度 > 后半部的长度 分两部分复制
            memcpy(dst, rb->buf + rb->head, len_back * sizeof(DATA_TYPE));           // 后半部
            memcpy(dst + len_back, rb->buf, (cp_len - len_back) * sizeof(DATA_TYPE));// 前半部
        }
    }
    return cp_len;
}

// 定义并初始化一个缓存区
static ring_buf log_buf = {
    .head = 0,
    .tail = 0,
    .size = 0,
    .capacity = BUF_SIZE,
    .isempty = ring_buf_isempty,
    .put = ring_buf_put,
    .gets = ring_buf_gets,
};


int main()
{

    // 长度只有5 存入10，只保留了后5
    for (int i=0; i<BUF_SIZE * 2; ++i)
        log_buf.put(&log_buf, 'a' + i);

    DATA_TYPE dst[20];
    int len = log_buf.gets(&log_buf, dst, 2); // 只取了后5的前2
    for (int i=0; i<len; ++i) 
        printf("%c ", dst[i]);

// stdout:
        // f g

    return 0;
}
