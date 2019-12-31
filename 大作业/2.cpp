#include<iostream>
using namespace std;
template<class T>
class MinHeap{
public:
    MinHeap(int size);
    MinHeap(T arr[],int n);
    bool insert(T ele);
    bool pop();
    bool isFull();
    bool isEmpty();
    void print();
    int Size();
    T top();
private:
    T *heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start,int end);
    void siftUp(int start);
};

template<class T>
MinHeap<T>::MinHeap(int size){
    maxHeapSize=size;
    heap=new T[size];
    currentSize=0;
    maxHeapSize=size;
}

template<class T>
MinHeap<T>::MinHeap(T arr[],int n){
    maxHeapSize=n;
    heap=new T[maxHeapSize];
    currentSize=n;
    for(int i=0;i<n;i++){
        heap[i]=arr[i];
    }
    int currentPos=(n-2)/2;
    while(currentPos>=0){
        siftDown(currentPos,currentSize-1);
        currentPos--;
    }
}

template<class T>
bool MinHeap<T>::isFull(){
    return currentSize==maxHeapSize;
}

template<class T>
bool MinHeap<T>::isEmpty(){
    return currentSize==0;
}

template<class T>
void MinHeap<T>::siftDown(int start,int end){
    T tmp=heap[start];
    int i=start;
    int j=i*2+1;
    while(j<=end){
        if(j<end&&heap[j]>heap[j+1])j++;
        if(tmp>heap[j]){
           heap[i]=heap[j];
           i=j;
           j=i*2+1; 
        }
        else{
            break;
        }
    }
    heap[i]=tmp;
}

template<class T>
void MinHeap<T>::siftUp(int start){
    T tmp=heap[start];
    int j=start,i=(j-1)/2;
    while(j>0){
        if(heap[i]>tmp){
            heap[j]=heap[i];
            j=i;
            i=(j-1)/2;
        }
        else{
            break;
        }
    }
    heap[j]=tmp;
}

template<class T>
bool MinHeap<T>::pop(){
    if(this->isEmpty())return false;
    heap[0]=heap[currentSize-1];
    siftDown(0,--currentSize-1);
    return true;
}

template<class T>
bool MinHeap<T>::insert(T ele){
    if(this->isFull())return false;
    heap[currentSize]=ele;
    siftUp(currentSize++);
    return true;
}

template<class T>
void MinHeap<T>::print(){
    for(int i=0;i<currentSize;i++){
        cout<<heap[i]<<' ';
    }
    cout<<endl;
}

template<class T>
int MinHeap<T>::Size(){
    return currentSize;
}

template<class T>
T MinHeap<T>::top(){
    return heap[0];
}

struct lessInCome{
    int val;
    bool operator>(lessInCome& x){
        return val<x.val;
    }
    friend bool operator<(const int x,const lessInCome& y){
        return x<y.val;
    }
    lessInCome(int v):val(v){}
    lessInCome(){}
    friend ostream& operator<<(ostream& out,const lessInCome& c){
        out<<c.val;
        return out;
    }
};
struct moreInCome{
    int val;
    bool operator>(moreInCome& x){
        return val>x.val;
    }

    friend bool operator>(const int x,const moreInCome& y){
        return x>y.val;
    }
    moreInCome(int v):val(v){}
    moreInCome(){}
    friend ostream& operator<<(ostream& out,const moreInCome& c){
        out<<c.val;
        return out;
    }
};




int main()
{
    ios::sync_with_stdio(false);
    int n,ans=0;
    cin>>n;
    MinHeap<lessInCome> minHeap(n);//小根堆存放大 k/2 个数据  
    MinHeap<moreInCome> maxHeap(n);//大根堆存放小 k/2 个数据

    for(int i=0,x;i<n;i++){
        cin>>x;
        if(maxHeap.Size()<minHeap.Size()){
            if(x<minHeap.top()){
                minHeap.insert(x);
                x=minHeap.top().val;
                minHeap.pop();
                maxHeap.insert(x);
            }
            else
                maxHeap.insert(x);
        }
        else{
            if(maxHeap.Size()==0){
                minHeap.insert(x);
            }
            else if(x>maxHeap.top()){
                maxHeap.insert(x);
                x=maxHeap.top().val;
                maxHeap.pop();
                minHeap.insert(x);
            }
            else
                minHeap.insert(x);
        }
        if(i&1)
            ans=(minHeap.top().val+maxHeap.top().val)/2;
        else
            ans=minHeap.top().val;
        //minHeap.print();
        //maxHeap.print();
        //cout<<"ans:"<<ans<<endl;
        cout<<ans<<endl;
    }
    //cout<<ans<<endl;
    return 0;
}
/*
5
100000
40000
30000
60000
200000

*/