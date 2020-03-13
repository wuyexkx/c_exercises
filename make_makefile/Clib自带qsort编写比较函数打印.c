#include <stdio.h>
#include <stdlib.h>
#include "qs_compare.h"
#include "print_map.h"

int main()
{
    struct map kv_map[4];
    kv_map[0].key = 4;
    kv_map[0].value = 0;
    kv_map[1].key = 3;
    kv_map[1].value = 1;
    kv_map[2].key = 2;
    kv_map[2].value = 2;
    kv_map[3].key = 1;
    kv_map[3].value = 3;

    print_map(&kv_map, 4);
    
    qsort(&kv_map, 4, (sizeof(struct map)), qs_compare);

    print_map(&kv_map, 4);

    return 0;
}
