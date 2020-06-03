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

// 循环顺序缓冲区
// 满了会覆盖前面的，先进先出。空间全部用上了
// 只是存入 和 遍历，没有取出
#define BUF_SIZE    (5)
char buf[BUF_SIZE];
int head = 0;
int tail = 0;

// 放入数据
void put(char c)
{   
    // 从第一个开始， 满了就舍弃head
    tail = (tail + 1) % BUF_SIZE;
    if (tail == head)
        head = (head + 1) % BUF_SIZE;
    buf[tail] = c;
}
// 打印前n个数据
void print(int n)
{
    int p = head;
    while (--n && (p + 1) % BUF_SIZE != head) {
        printf("%c ", buf[p]);
        p = (p + 1) % BUF_SIZE;
    }
    printf("%c ", buf[p]);
}


int main()
{
    put('a');
    put('b');
    put('c');
    put('d');
    put('e');

    put('f');
    put('g');
    put('h');
    put('i');
    put('j');

    print(4);

    return 0;
}