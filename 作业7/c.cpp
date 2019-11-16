#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//思路：种类并查集+二分法
struct BadGuys{
    int g1,g2;
    int val;
    friend istream& operator >>(istream& in,BadGuys& bg){
        in>>bg.g1>>bg.g2>>bg.val;
        return in;
    }
    friend ostream& operator <<(ostream& out,const BadGuys& bg){
        out<<bg.g1<<' '<<bg.g2<<' '<<bg.val;
        return out;
    }
    bool operator <(const BadGuys& bg){
        return val<bg.val;
    }
};
bool check(){

}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<BadGuys> badguys(n);
    
    for(auto& bg:badguys)
        cin>>bg;
    sort(badguys.begin(),badguys.end());

    for(auto& bg:badguys)
        cout<<bg<<endl;


    return 0;
}