#include<iostream>
using namespace std;
bool finish_reading(int *page,int n,int speed,int t){
    int total=0;
    for(int i=0;i<n;i++){
        total+=(page[i]-1)/speed+1;
    }
    return total<=t;
}
int main()
{
    int max_speed = 0,min_speed = 1;
    int n,t;
    int page[10000];
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>page[i];
        if(page[i]>max_speed)max_speed=page[i];
    }
    int mid_speed;
    while(min_speed<max_speed-1){
        mid_speed=(max_speed+min_speed)/2;
        if(finish_reading(page,n,mid_speed,t)){
            max_speed=mid_speed;
        }
        else min_speed=mid_speed;
    }
    cout<<max_speed;
    return 0;
}