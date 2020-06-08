// 两种方法

// 小的数累加，既能被a也能被b整除则为最小公倍数
#include <stdio.h>

int  main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int aa=a, bb=b;
        if (a < b) {
            a = b + 1;
            while (a % b || a % aa) a++;
            printf("%d\n", a);
        }
        else if (a > b) {
            b = a + 1;
            while (b % a || b % bb) b++;
            printf("%d\n", b);
        }
        else printf("%d\n", a);
    }
    return 0;
}


// 最小公倍数 = 两数之积 / 最大公约数
// #include <stdio.h>

// int  main()
// {
//     int a, b;
//     while (scanf("%d%d", &a, &b) != EOF) {
//         // 最小公倍数 = 两数之积 / 最大公约数
//         int aa = a, bb = b;
//         // 求最大公约数
//         int t;
//         while (t = aa % bb) {
//             aa = bb;
//             bb = t;
//         }
//         printf("%d\n", a * b / bb);
//     }
//     return 0;
// }