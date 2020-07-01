#if 0
filename="$0"
name="${filename%.*}"
CC=g++
$CC -o $name $filename
$name $@
rm $name
exit
#endif


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int steps = 0;

void move(int l, const string& x, const string& y)
{ 
    cout << "Move " <<  l << (" from " + x + " to " + y) << endl; 
    steps++;
}

void hanob(int n, const string a, const string b, const string c)
{
    if (n == 1) {
        move(n, a, b);
        move(n, b, c);
        return;
    } else {
        hanob(n-1, a, b, c);
        move(n, a, b);
        hanob(n-1, c, b, a);
        move(n, b, c);
        hanob(n-1, a, b, c);
    }
}

int main()
{
    int n;
    cin >> n;
    hanob(n, "left", "mid","right");
    cout << "It will move " << steps << " steps." << endl;
    return 0;
}