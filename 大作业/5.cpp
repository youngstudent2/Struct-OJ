#include<iostream>
using namespace std;
struct Element
{
    bool filled;
    int max,min;
    Element():filled(false){}
};

inline int Max(int a,int b){
    return a>b?a:b;
}

inline int Min(int a,int b){
    return a<b?a:b;
}

inline void inputHandle(int &n,int *&income){
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>income[i];
}

inline int buildEles(int n,int *arr,Element *&eles){
    int min=0xfffffff,max=0;
    for(int i=0;i<n;++i){
        min=Min(min,arr[i]);
        max=Max(max,arr[i]);
    }
    int size=(max-min)/(n-1);
    size=size>0?size:1;
    int num=(max-min)/size+1;
    eles=new Element[num];
    
    int pos;
    for(int i=0;i<n;++i){
        pos=(arr[i]-min)/size;
        if(eles[pos].filled){
            eles[pos].min=Min(eles[pos].min,arr[i]);
            eles[pos].max=Max(eles[pos].max,arr[i]);
        }
        else{
            eles[pos].min=arr[i];
            eles[pos].max=arr[i];
        }
        eles[pos].filled=true;
    }
    return num;
}

int maxBreak(Element *eles,int n){
    int res=0;
    int lastMax=eles[0].max;
    for(int i=0;i<n;++i){
        if(eles[i].filled){
            res=Max(eles[i].min-lastMax,res);
            lastMax=eles[i].max;
        }
    }
    return res;
}
int main()
{
    int n;
    int *income;
    Element *eles;
    inputHandle(n,income);
    int eleNum=buildEles(n,income,eles);
    cout<<maxBreak(eles,eleNum);
    return 0;
}