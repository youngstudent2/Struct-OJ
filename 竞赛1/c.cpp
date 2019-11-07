#include<iostream>
#include<cstring>
using namespace std;
void cal(int *a, int &la, int *b, int &lb) {
    int *c = new int[501];
    for (int i = 0; i < 101; i++)c[i] = 0;
    int maxlen = la > lb ? la : lb;
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < lb; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    int lc = 0;
    for (;lc<=la+lb-2||c[lc]; lc++) {
        if (c[lc] > 9) {
            c[lc + 1] += c[lc] / 10;
            c[lc] %= 10;
        }
    }
    for (int i = 0; i < lc; i++) {
        a[i] = c[i];
    }
    la = lc;
}
int main()
{
    int n;
    cin >> n;
    char tmp[101];
    int bignum[10][501] = {0};
    int len[10];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        int count = 0;
        len[i] = strlen(tmp);
        for (int j = len[i]-1; j >= 0; j--) {
            bignum[i][count++] = tmp[j]-'0';
        }
    }
 
     
 
    for (int i = 1; i < n; i++) {
        cal(bignum[0], len[0], bignum[i], len[i]);
    }
     
    for (int i = len[0] - 1; i >= 0; i--) {
        cout << bignum[0][i];
    }
    //cout << endl << len[0];
    //system("pause");
    return 0;
}