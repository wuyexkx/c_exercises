#include <stdio.h>

// switch() 括号里只能放整型数 （c语言还有求模是只能是整型）
//      多分枝

int main()
{
    float b = 3.4;
    // printf("%f", b % 2); // 不合法 invalid operands of types ‘float’ and ‘int’ to binary ‘operator%’ printf("%f", b % 2);

    unsigned int a = -10;
    unsigned int c = a + 2;
    printf("%d\n", c);

    return 0;
}