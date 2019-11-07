#include<iostream>
using namespace std;
int main()
{
    long long int *w;
    long long int n;
    long long int maxv=0, tmp;
    cin >> n;
    w = new long long int[n];
    for (int i = 0; i < n; i++)cin >> w[i];
    for (int l = 0, r = n - 1; l < r;) {
        if (w[l] <= w[r]) {
            tmp = w[l] * (r - l);
            if (tmp > maxv)
                maxv = tmp;
            l++;
        }
        else {
            tmp = w[r] * (r - l);
            if (tmp > maxv)
                maxv = tmp;
            r--;
        }
    }
    cout << maxv;
    delete[] w;
 
    return 0;
}