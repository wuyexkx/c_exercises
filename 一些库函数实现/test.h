#ifndef __TEST_H_
#define __TEST_H_

#include <cstdio>

typedef	int* data_type;
void print(const void* src, const size_t n)
{
	data_type psrc = (data_type)src;
	for (int i=0; i<n; ++i) 
		printf("%d ", psrc[i]); 
	printf("\n");
}



#endif