#include <stdio.h>

typedef unsigned int uint;

/*
兰州烧饼
烧饼有两面，要做好一个兰州烧饼，要两面都弄热。
当然，一次只能弄一个的话，效率就太低了。
有这么一个大平底锅，一次可以同时放入k个兰州烧饼，一分钟能做好一面。
而现在有n个兰州烧饼，至少需要多少分钟才能全部做好呢？
*/

// Note: 
//      1.计算总的面数
//      2.面比锅容量小的情况
// 共3个饼 锅每次最多2面。共6面，每次2面，共3次即可
// 共7个饼 锅每次最多3面。共14面，每次3面，共4+2次即可
// 共3个饼 锅每次最多4面。共6面，每次4面，共2次即可
void lanzhoushaobing(uint nums, uint k)
{
    if(nums <= k){
        printf("\ntimes: %d\n", 2);
        return;
    }

    uint quotient  = nums * 2 / k;
    uint residue  = nums * 2 % k;
    if(residue == 0){   // 刚好可以煎完 
        printf("\ntimes: %d\n", quotient);
    } else{             // 剩下还需要两面
        printf("\ntimes: %d\n", quotient + 2);
    }
}

int main()
{
    uint nums, k;
    printf("\nPlease enter 2 numbers separated by 'space': ");
    scanf("%d %d", &nums, &k);

    lanzhoushaobing(nums, k);

    return 0;
}
