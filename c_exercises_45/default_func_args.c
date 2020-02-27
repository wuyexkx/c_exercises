#include <stdio.h>

void _func(int i, int *p)
{
    printf("i=%d p=%p\n", i, p);
}

// C语言函数参数没有默认值，只能通过宏实现。可以给任意参数默认值
//   name为空(#name = "" or " ")，取缺省值defval，不为空取name的值。#字符串化，##连接任意
    //   解释name + 0：
    //      name + 0 如果 name 为空 变成 +0 正0 也就是 0
    //      如果没有+0 如果为空 就成  ""[0] ? : defval 
    //      ?表达式，缺少了一个表达式，当然就错了
#define DEFARG(name, defval) ( #name[0] ? (name + 0) : defval )
//  将宏绑定到对应函数
#define func(arg0, arg1) _func(DEFARG(arg0, 8), DEFARG(arg1, (int*)0))

int main()
{
    int i=9;

    // 有参数返回参数，无则返回默认defval
    if(DEFARG(, 9) == 9)
        printf("DEFARG(, 9)\n");
    if(DEFARG( , 9) == 9)
        printf("DEFARG( , 9)\n");
    if(DEFARG(i, 8) == 9)
        printf("DEFARG(i, 8)\n");
    
    // 函数默认参数，无参数则使用默认参数
    func( , );
    func(88, );
    func( , &i);
    func(888, &i);

/* OUTPUT:
        DEFARG(, 9)
        DEFARG( , 9)
        DEFARG(i, 8)
        i=8 p=0000000000000000
        i=88 p=0000000000000000
        i=8 p=000000000022FE4C
        i=888 p=000000000022FE4C
*/
    return 0;
}
