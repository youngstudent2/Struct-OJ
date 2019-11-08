//注：这份代码是面向OJ写的，本地测试99%会出错
#include<iostream>
#include<string>
using namespace std;
void getNext(string &p, int *next) {
    next[0] = -1;
    for (int i = 0, j = -1; i < p.length();) {
        if (j == -1 || p[i] == p[j]) {
            ++i; ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}
 
bool KMP(const string &s, const string &p, int *next) {
    int count = 0;
    int i = 0, j = 0;
    int slen = s.length()-1;
    int plen = p.length()-1;
    while (i < slen) {
        if (j == -1 || s[i] == p[j]) {
            ++i; ++j;
            if (j == plen) {
                cout << i - j << ' ';
                j = next[j];
                ++count;
            }
        }
        else {
            j = next[j];
        }
    }
 
    return count > 0;
}
 
int main()
{
    string s1, s2;
    int *next;
     
    getline(cin, s1);
    getline(cin, s2);
 
    next = new int[s2.length() + 2];
    getNext(s2, next);
    if (!KMP(s1, s2, next))cout << "false";

    return 0;
}
/*
abc abcdab abcdabcdabde
abcd
0 1 2 3 4 5 6 7
5 6 7
 
aaaaaaaaaaaa
a
*/