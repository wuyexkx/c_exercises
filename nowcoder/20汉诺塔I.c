
#if 0
filename="$0"
name="${filename%.*}"
CC=gcc
$CC -o $name $filename
$name $@
rm $name
exit
#endif

#include <stdio.h>

// 有n个塔
// 将x上的n-1个塔 经过 z 移动到 y
// 把x上最后一个移动到z
// 将y上的n-1个塔 经过 x 移动到 z
void move(const char src, const char dst)
{ printf("%c -> %c\n", src, dst); }

// n    x y z
void hanoi(int n, char x, char y, char z)
{
    if (n == 1) {
        move(x, z);
    }
    else {
        hanoi(n-1, x, z, y);
        move(x, z);
        hanoi(n-1, y, x, z);
    }
}
// n个塔的移动次数为(2 ^ n - 1)  1 3 7 15 31 
int main()
{
    hanoi(5, 'x', 'y', 'z');
    return 0;
}

// 牛客原题  汉诺塔问题I 
class Hanoi {
public:
    vector<string> getSolution(int n) {
        // write code here
        vector<string> res;
        string x("left");
        string y("mid");
        string z("right");
        hano(n, x, y, z, res);
        return res;
    }
    void hano(int n, string& x, string& y, string& z, vector<string>& res) {
        if (n == 1) {
            move(x, z, res);
        } else {
            hano(n-1, x, z, y, res);
            move(x, z, res);
            hano(n-1, y, x, z, res);
        }
    }
    void move(string& src, string& dst, vector<string>& res) {
        res.push_back("move from " + src + " to " + dst);
    }
};

