#include<iostream>
#include<vector>
#include<string>
using namespace std;

int fun(string& str)
{
    struct Flag {
        char num;
        char alph;
        char Alph;
        char sign;
    } flag = {0, 0, 0, 0};

    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            flag.Alph = 1;
        else if (str[i] >= 'a' && str[i] <= 'z')
            flag.alph = 1;
        else if (str[i] >= '0' && str[i] <= '9')
            flag.num = 1;
        else 
            flag.sign = 1;                          
    }

    if (flag.Alph + flag.alph + flag.num + flag.sign == 4)
        return 1;
    else
        return 0;
}

int main()
{
    vector<string> vec;
    
    string str;
    while (cin >> str) {
        vec.push_back(str);

        if (getchar() == '\n')
            break;
    }
    
    for (int i=0; i<vec.size(); i++) {
        int len = vec[i].size();
        if (len > 120 || len < 8)
            cout << 1 << endl;
        else if (fun(vec[i])) {
            cout << 0 << endl;
        } 
        else 
            cout << 2 << endl;    
    }
    
    return 0;
}