#include <stdio.h>
#include <stdlib.h>

#define TEMPLATE    int 
# include "stack_macro.h"

#define TEMPLATE    char 
# include "stack_macro.h"

// gcc -E .\stack_macro.c -I .\include -o stack_macro.i
// make clean | cmake .. | make
int main()
{
    stack(int) s1 = init(stack(int));
    
    int i = 1;
    s1.push(&s1, &i);
    i = 2;
    s1.push(&s1, &i);
    i = 3;
    s1.push(&s1, &i);

    printf("%d ", s1.pop(&s1));
    printf("%d ", s1.pop(&s1));
    printf("%d ", s1.pop(&s1));
    s1.pop(&s1);

    printf("\n");
    stack(char) s2 = init(stack(char));
    char c = 'o';
    s2.push(&s2, &c);
    c = 'l';
    s2.push(&s2, &c);
    c = 'l';
    s2.push(&s2, &c);
    c = 'e';
    s2.push(&s2, &c);
    c = 'H';
    s2.push(&s2, &c);

    printf("%c ", s2.pop(&s2));
    printf("%c ", s2.pop(&s2));
    printf("%c ", s2.pop(&s2));
    printf("%c ", s2.pop(&s2));
    printf("%c ", s2.pop(&s2));
    s2.pop(&s2);

    s1.free(&s1);
    s2.free(&s2);

    printf("\n");

    return 0;
}