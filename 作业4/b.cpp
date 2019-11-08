#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack {
    T data[201];
    int t;
public:
    Stack() {
        t = -1;
    }
    bool empty() {
        return t < 0;
    }
    T top() {
        return data[t];
    }
    int push(T buf) {
        if (t >= 200)return -1;
        data[++t] = buf;
        return t;
    }
    T pop() {
        return data[t--];
    }
    void output(){
        for(int i=0;i<=t;i++){
            cout<<'/'<<data[i];
        }
        if(empty())cout<<'/';
    }
};
 
int main()
{
    string path;
    cin>>path;
    if(path[path.length()-1]!='/')path.append("/");
    Stack<string> list;
    string tmp;
    int count=0;
    int i=0;
    while(i<path.length()){
        ++count;
        if(path[i]=='/'){
            tmp=path.substr(i-count+1,count-1);
            //cout<<tmp<<endl;
            count=0;
            if(tmp==".."){
                if(!list.empty())
                    list.pop();
            }
            else if(tmp=="."||tmp.empty()){
 
            }
            else{
                list.push(tmp);
            }
        }
        ++i;
    }
 
    list.output();
 
    return 0;
}