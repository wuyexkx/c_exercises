#include "qs_compare.h"

int qs_compare(const void *a, const void *b)
{
    return ((struct map *) a)->key - ((struct map *) b)->key; 
}
