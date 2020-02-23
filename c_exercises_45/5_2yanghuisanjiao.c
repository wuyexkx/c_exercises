#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
杨辉三角
还记得中学时候学过的杨辉三角吗？
具体的定义这里不再描述，你可以参考以下的图形： 
      1 
     1 1 
    1 2 1 
   1 3 3 1 
  1 4 6 4 1 
1 5 10 10 5 1

输入 输入数据包含多个测试实例，
    每个测试实例的输入只包含一个正整数n（1<=n<=30），
    表示将要输出的杨辉三角的层数。

输出 对应于每一个输入，请输出相应层数的杨辉三角，
    每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。
*/

/*
Note:
    每行第i个数（除了第一个和最后一个数是1），其他数是等于上一行第i数和第i-1数之和

*/

void yanghuisanjiao()
{
    uint n, result=0;
    uint nums1[30] = {1};
    uint nums2[30];
    uint temp[30];

    while(scanf("%d", &n) != EOF){
        // 杨辉三角
        uint row;
        for(row=1; row<n+1; ++row){         /* 控制行 1~n (row) */  for(int i=(n-row)*3; i>0; --i) printf(" "); // 每行的起始位置                                         
            for(uint j=0; j<row; ++j){      /* 控制每行的数据 0~row-1 (j) */
                // 每行第一个和最后一个是1
                if(j>0 && j<row-1){  
                    nums2[j] = nums1[j] + nums1[j-1];
                }
                else{
                    nums2[j] = 1;
                }                    
                temp[j] = nums2[j];
                printf("%5d ", temp[j]);
            }
            // 保存上一行数据
            for(uint i=0; i<row; ++i){
                nums1[i] = temp[i];
            }
            printf("\n"); // 每行末尾换行
        }
        printf("\n");  
    }
}

int main()
{
    yanghuisanjiao();

    return 0;
}
