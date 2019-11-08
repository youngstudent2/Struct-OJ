#include<iostream>
using namespace std;
#define SIZE 30
inline int read(char& firstNum)
{
    int sum=0;
    char ch=getchar();
 
    while(ch>'9'||ch<'0')ch=getchar();
    firstNum=ch-'0';
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum;
}
 
int main()
{
    int n;
    char firstNum;
    int x;
    int hash[SIZE];
    while(cin>>n){
        for(int i=0;i<SIZE;i++)hash[i]=-1;
        for(int i=0;i<n;i++){
            x=read(firstNum);
            for(int stop=firstNum-1;hash[firstNum]!=-1&&stop!=firstNum;firstNum=(firstNum+1)%SIZE);
            hash[firstNum]=x;
        }
        for(int i=0,count=0;i<SIZE;i++){
            if(hash[i]>=0){
                cout<<hash[i];
                 
                if(++count<n)cout<<',';
            }
             
        }
        cout<<endl;
    }
     
    return 0;
}