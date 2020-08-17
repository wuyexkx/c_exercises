#include <stdio.h>

// 对数据实现 加法 和 乘法 然后把数据写回
// void*的使用，参数为oid* 函数内部转换
typedef struct data {
    int a;
    int b;
    int result;
} Data;

void add(void* param)
{
    Data* p = (Data*)param;
    p->result = p->a + p->b;
}
void mul(void* param)
{
    Data* p = (Data*)param;
    p->result = p->a * p->b;
}

void cal(void* param, void* func)
{
    ((void (*)(void*))func)(param);
}

int main()
{
    Data data1 = {1, 2};
    Data data2 = {3, 4};

    cal(&data1, add);
    cal(&data2, mul);

    printf("%d  %d\n", data1.result, data2.result); // 3  12
    
    return 0;
}