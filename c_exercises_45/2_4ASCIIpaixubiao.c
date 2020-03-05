#include <stdio.h>
#include <math.h>
typedef unsigned int uint;

/*
ASCII码排序
输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。

输入 第一行输入一个数N,表示有N组测试数据。
     后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
输出 对于每组输入数据，输出一行，字符中间用一个空格分开。
*/


/*
Note:
    3个数排序，两两交换，0和1比较，0和2比较，1和2比较
*/

void ASCIIpaixubiao()
{
    // 不用数组也行 直接a b c
    char ascii_char[4]; // 存放在高地址，
    uint n;             // 存放在低地址

    printf("\nplease enter total: ");
    scanf("%d", &n);

    while(n--){
        printf("\nPlease enter the 3 ASCII char, such as Abc: ");
        scanf("%s", ascii_char);

        char temp;
        if(ascii_char[1] < ascii_char[0]){
            temp = ascii_char[0];
            ascii_char[0] = ascii_char[1];
            ascii_char[1] = temp;
        }
        if(ascii_char[2] < ascii_char[0]){
            temp = ascii_char[0];
            ascii_char[0] = ascii_char[2];
            ascii_char[2] = temp;
        }
        if(ascii_char[2] < ascii_char[1]){
            temp = ascii_char[1];
            ascii_char[1] = ascii_char[2];
            ascii_char[2] = temp;
        }        
        
        printf( "\nsort ASCII: %d %c %c %c\n", 
                n, ascii_char[0], ascii_char[1], ascii_char[2]);
    }
}

int main()
{
    ASCIIpaixubiao();

    return 0;
}
