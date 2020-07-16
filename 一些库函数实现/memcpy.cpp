#include <iostream>
#include <cassert>
// #include <cstring>
#include "test.h"

using namespace std;

// 返回值的目的是满足链式表达
// ====================================================================
// // 考虑不周全
// // 当 dest 在 src 的内部时，dest的起始将覆盖掉 src 的数据，导致 src 后面数据丢失
// // src---------------
// // 			dest---------------
// void* memcpy(void* dest, const void* src, size_t n)
// {
// 	assert(dest != NULL && src != NULL);

// 	char* d = (char*)dest;
// 	char* s = (char*)src;
// 	while (n--) {
// 		*d++ = *s++;
// 	}
//	return dest;
// }

void* memcpy(void* dest, const void* src, size_t n)
{
	assert(dest != NULL && src != NULL);

	char* d = (char*)dest;
	char* s = (char*)src;
	if (d > s && d < s + n) { 	// 从后往前复制
		d += n - 1;
		s += n - 1;
		while (n--) {
			*d-- = *s--;
		}
	} 
	else {						// 从前往后复制
		while (n--) {
			*d++ = *s++;
		}
	}
	return dest;
}
// ====================================================================

int main()
{
	// 没有重叠部分
	int src1[5] = {1,2,3,4,5};
	int dst1[10];
	memcpy(&dst1[0], src1, sizeof(int) * 5);
	cout << "src1: "; print(src1, 5);
	cout << "dst1: "; print(dst1, 10);


	// 重叠 dest---src-------
	int* dst2 = (int*)malloc(sizeof(*dst2) * 10);
	int* src2 = dst2 + 3;
	// 对src2赋值
	for (int i=0; i<5; ++i) src2[i] = i;

	cout << "\naddress:\n" << dst2 << "\n" << src2 << endl;
	cout << "src2: "; print(src2, 5);
	// 从src2 往 dst2 memcpy 5 个数
	memcpy(dst2, src2, 5 * sizeof(int));
	cout << "src2: "; print(src2, 5); // src src2已经被改变
	cout << "dst2: "; print(dst2, 5);


	// 重叠 src---dest-------
	int* src3 = (int*)malloc(sizeof(*src3) * 10);
	int* dst3 = src3 + 3;
	// 对src3赋值
	for (int i=0; i<5; ++i) src3[i] = i;
	cout << "\naddress:\n" << src3 << "\n" << dst3 << endl;
	cout << "src3: "; print(src3, 5);
	// 从src3 往 dst3 memcpy 5 个数
	memcpy(dst3, src3, 5 * sizeof(int));
	cout << "src3: "; print(src3, 5);
	cout << "dst3: "; print(dst3, 5);	

	// src1: 1 2 3 4 5 
	// dst1: 1 2 3 4 5 21992 689871264 21992 317540080 32766 

	// address:
	// 0x55e829dd7280
	// 0x55e829dd728c
	// src2: 0 1 2 3 4 
	// src2: 3 4 2 3 4 
	// dst2: 0 1 2 3 4 

	// address:
	// 0x55e829dd72b0
	// 0x55e829dd72bc
	// src3: 0 1 2 3 4 
	// src3: 0 1 2 0 1 
	// dst3: 0 1 2 3 4 

	return 0;
}


