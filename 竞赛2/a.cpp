#include<iostream>
using namespace std;
struct LUT{
    int ele;
    int time;
    bool operator>(const LUT& l){
        return this->time>l.time;
    }
    bool operator<=(const LUT& l){
        return this->time<=l.time;
    }
};
int partition(LUT *a, int p, int q)
{
    LUT pivot = a[p];
    int i = p, j = q;
    while (i < j)
    {
        while (i < j && a[j] > pivot)
            j--;
        a[i] = a[j];
 
        while (i < j && a[i] <= pivot)
            i++;
        a[j] = a[i];
    }
 
    a[i] = pivot;
    return i;
}
 
void quick_sort(LUT *a, int p, int q)
{
    if (p >= q)
        return;
 
    int m = partition(a, p, q);
    quick_sort(a, p, m - 1);
    quick_sort(a, m + 1, q);
}
int main(){
    int n,k;
    int count=0;
    bool flag;
    int a;
    LUT lut[1000];
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        flag=false;
        for(int j=0;j<count;j++){
            if(lut[j].ele==a){
                flag=true;
                lut[j].time++;
            }
        }
        if(!flag){
            lut[count].ele=a;
            lut[count].time=1;
            count++;
        }
    }
    cin>>k;
    quick_sort(lut,0,count-1);
    for(int i=count-1;i>count-1-k;i--){
        cout<<lut[i].ele<<' ';
    }
 
 
    return 0;
}