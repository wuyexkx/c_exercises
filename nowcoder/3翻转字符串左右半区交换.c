#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[100001];
    int n;
    while (scanf("%d", &n) != EOF) {
        //gets(s);
        scanf("%s", s);
        int len = strlen(s);
        for (int i=n; i<len; ++i)
            printf("%c", s[i]);
        for (int i=0; i<n; ++i)
            printf("%c", s[i]);
        printf("\n");
    }
     
    return 0;
}

// C++
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s;
    int n;
    cin >> n;
    cin >> s; 
    cout << s.substr(n) << s.substr(0, n) << endl; // string的输出处理
    return 0;
}