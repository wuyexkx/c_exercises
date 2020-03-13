#include <stdio.h>
#include "print_map.h"

void print_map(struct map *p, const int length)
{
    for(int i; i<length; ++i){
        printf("(%d %d) ", p[i].key, p[i].value);
    }
    printf("\n");
}
