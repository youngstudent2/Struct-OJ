#include<iostream>
#include<string>
#define DefaultSize 5000 //假设市民最大数量
using namespace std;

int *tmpHeap;

//最小堆
template <class E>
class minHeap {
	E *heap;
	int currentSize;  //当前元素个数
	int maxSize; //最大容量
	void siftUp(int start) {
		int j = start;
		int i = (j - 1) / 2;
		E tmp = heap[j];
		while (j > 0) {//沿父结点路径向上直达根
			if (heap[i] <= tmp)break;//父结点值小, 不调整
			else {//父结点结点值大, 调整
				heap[j] = heap[i];
				j = i;
				i = (i - 1) / 2;
			}
		}
		heap[j] = tmp;
	}
	void siftDown(int start, int m) {
		int i = start;
		int j = 2 * i + 1; //j是i的左子女位置
		E tmp = heap[i];
		while (j <= m) {   //检查是否到最后位置
			if (j<m&&heap[j]>heap[j + 1])j++;     //让j指向两子女中的小者
			if (tmp <= heap[j])break;  //小则不做调整
			else { heap[i] = heap[j]; i = j; j = 2 * j + 1; }//否则小者上移, i, j下降
		}
		heap[i] = tmp;//回放tmp中暂存的元素
	}
public:
	//创建
	minHeap(int sz) {
		maxSize = (DefaultSize < sz) ? sz : DefaultSize;
		heap = new E[maxSize];  	//创建堆空间
		if (heap == NULL) {
			cerr << "堆存储分配失败！" << endl;
			exit(1);
		}
		currentSize = 0;				//建立当前大小
	}
	//插入
	bool Insert(const E& x) {
		//将x插入到最小堆中
		if (currentSize == maxSize) 	//堆满
		{
			cerr << "Heap Full" << endl; 
			return false;
		}
		heap[currentSize] = x;  		//插入
		siftUp(currentSize);			//向上调整
		currentSize++;				//堆计数加1
		return true;
	};
	//删除
	E Remove() {
		if (!currentSize) {		//堆空, 返回false
			return -1;
		}
		E x = heap[0];
		heap[0] = heap[currentSize - 1];
		currentSize--;
		siftDown(0, currentSize - 1);    	//自上向下调整为堆
		return x;
	};
	//得到堆顶的元素
	E getHeapTop() {
		return heap[0];
	}

	//得到当前元素个数
	int getSize() { return currentSize; }
};

void mystoi(string s[], int *a, int sum) { //将输入的字符串转化为整数，Check标记转化为-1
	for (int i = 0; i < sum; ++i)
	{
		if (s[i] == "Check")
			a[i] = -1;
		else {
			a[i] = 0;
			for (unsigned int j = 0; j < s[i].size(); ++j)
				a[i] = a[i] * 10 + s[i][j] - '0';
		}
	}
}

void topKincome(int *a, int n, int k) {
	minHeap<int> minheap(k);

	int i = 0;
	while (i < n) {  //执行check次而不是n次
		for (; i < n; ++i)
		{
			if (a[i] == -1) { i++; break; }
			else if (minheap.getSize() < k)  //堆未满
				minheap.Insert(a[i]);
			else if (a[i] > minheap.getHeapTop()) {  //堆满，待插入元素大于当前堆顶，将堆顶换为待插入元素
				minheap.Remove();
				minheap.Insert(a[i]);
			}
		}
		int count = 0;
		tmpHeap[count] = minheap.Remove();
		++count;
		for (int j = 1; j < k&&minheap.getSize()>0; ++j, ++count)
			tmpHeap[count] = minheap.Remove();
		cout << tmpHeap[count - 1];
		for (int j = count - 2; j >= 0; j--)
			cout << ' ' << tmpHeap[j];
		cout << endl;
		for (int j = 0; j < count; ++j)
			minheap.Insert(tmpHeap[j]);
	}
}

int main() {
	int n, k;  
	cin >> n >> k;
	tmpHeap = new int[k];
	string *input = new string[2*n];   
	int *income = new int[2*n];
	int i = 0;
	int count = 0;  //Check数量
	for (; i - count < n; ++i) 
	{
		cin >> input[i];
		if (input[i] == "Check")
			count++;
	}
	mystoi(input, income, i);
	income[i] = -1;
	topKincome(income, i+1, k);  //主函数

	return 0;
}