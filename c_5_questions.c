#include<stdio.h>

// // 第一题
// int main()
// {
//     int a[] = {1,2,3,4,5};
//     int* p = (int*)(&a+1);
//     printf("%d  %d\n", *(p-1), *p-1); // 5 未定义
//     printf("%d %d %d %d\n", sizeof(a), sizeof(&a), sizeof(p), sizeof(&p)); // 20 8 8 8

//     return 0;
// }


// // 第二题
// int i=2, j, k;
// int main()
// {
//     int i=1, j=j;
//     printf("%d\n", j);  // 未定义。int j=j; c语言定义和赋值是分开的，等价于int j; j=j;
//                         // 就近原则，全部变量i和j在main中不可见，
//                         // 局部变量在栈上，没有初始化就是脏数，全局变量和static默认初始为0，裸机开发不一定。

//     j = i++;        
//     if(i+j<=3)  // i+j=3成立
//     { int k=1; }// {}局部变量k=1;

//     printf("%d\n",k++); // 0。这里的k是全局变量

//     return 0;
// }


// // 第三题
// #define S(x)    x+x
// int i, j, k=2;
// int main()
// {
//     int i=3;
//     if(j<i<k)
//     j = S(i++); // j = i++ + i++; 3+4=7  i=5
//     k = S(++i); // k = ++i + ++i;  i=7

//     printf("%d  %d\n", j, k); // 7  14 不懂

//     return 0;
// }


// // 第四题
// char arr[] = "hello";
// char* str()
// {
//     char str[] = "world";
//     return str;
// }
// void setp(char* p)
// { p = arr; }

// int main()
// {
//     char* p = "\0";
//     setp(p);
//     printf("%s  %s\n", p, str()); // 空字符     未定义
//                                   // setp中p并没有被修改，str()返回局部数组的头
//     return 0;
// }


// 第五题
int main()
{
    unsigned int a = 0xf7;
    unsigned char i = (unsigned char)a;
    char* b = (char*)&a;
    printf("%08x  %08x\n", i, *b);  // 000000f7  fffffff7
                                    // a和i都无符号且a<0xff，所以数值上a等于i，
                                    // (char*)&a a的地址转化成按字节取值的指针，这个指针指向有符号的char。
                                    // *((unsigned char*)&a) == 000000f7
                                    // *((char*)&a) == fffffff7
    return 0;
}