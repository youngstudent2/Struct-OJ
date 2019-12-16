#include<iostream>
using namespace std;
class BloomFilter{
private:

public:
    void store(char* s){

    }
    bool in(char* s){

    }
}
void inputHandle(int &m,BloomFilter &bf){
    int n;
    cin>>n>>m;
    char id[19];
    for(int i=0;i<n;i++){
        cin>>id;
        bf.store(id);
    }
    
}

void searchInFilter(int m,BloomFilter &bf){
    char id[19];
    for(int i=0;i<m;i++){
        cin>>id;
        cout<<(bf.in(id)?"true":"false")<<endl;
    }
}

int main()
{
    int m;
    BloomFilter bf;
    inputHandle(m,bf);
    searchInFilter(m,bf);
    return 0;
}