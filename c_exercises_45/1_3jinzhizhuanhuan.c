#include <stdio.h>

typedef unsigned int uint;

/*
进制转换
输入一个十进制数N，将它转换成R进制数输出。
*/


void jinzhizhuanhuan(int num, int k)
{
    uint n = num, residue, index=0;
    char result[60];

    if(num < 0)
        n = -num;
        
    while(n){
        residue = n%k;     // 余数
        switch (residue){
            case 10: result[index++] = 'A'; break;
            case 11: result[index++] = 'B'; break;
            case 12: result[index++] = 'C'; break;
            case 13: result[index++] = 'D'; break;
            case 14: result[index++] = 'E'; break;
            case 15: result[index++] = 'F'; break;
            default: result[index++] = residue+'0'; break;
        }
        n = n/k;           // 商 
    }
    // 符号判断 加 -
    if(num < 0)
    result[index++] = '-';

    for(int i=index-1; i>=0; --i)
        printf("%c", result[i]);

    printf("\n");
}

int main()
{
    int num, k;
    printf("\nPlease enter 2 numbers separated by 'space': ");

    scanf("%d %d", &num, &k);
    jinzhizhuanhuan(num, k);

    return 0;
}
