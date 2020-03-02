#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class Hash;
typedef unsigned long (Hash::*HashFunc)(const string&);
class Hash {
private:
	unsigned long JSHash(const string& str) {
		unsigned long hash = 1315423911;
		for (int i = 0; i < str.length(); ++i) {
			hash ^= ((hash << 5) + str.at(i) + (hash >> 2));
		}
		return hash;
	}
	unsigned long RSHash(const string& str) {
		int b = 378551;
		int a = 63689;
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); i++) {
			hash = hash * a + str.at(i);
			a = a * b;
		}
		return hash;
	}
	unsigned long BKDRHash0(const string& str) {
		unsigned long seed = 31;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash1(const string& str) {
		unsigned long seed = 131;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash2(const string& str) {
		unsigned long seed = 1313;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash3(const string& str) {
		unsigned long seed = 13131;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash4(const string& str) {
		unsigned long seed = 131313;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash5(const string& str) {
		unsigned long seed = 1313131;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long BKDRHash6(const string& str) {
		unsigned long seed = 13131313;//31 131 1313 13131 131313 1313131
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = (hash*seed) + str.at(i);
		}
		return hash;
	}
	unsigned long SDBMHash(const string& str) {
		unsigned long hash = 0;
		for (int i = 0; i < str.length(); ++i) {
			hash = str.at(i) + (hash << 6) + (hash << 16) - hash;
		}
		return hash;
	}
	unsigned long DJBHash(const string& str) {
		unsigned long hash = 5381;
		for (int i = 0; i < str.length(); ++i) {
			hash = ((hash << 5) + hash) + str.at(i);
		}
		return hash;
	}
	unsigned long DEKHash(const string& str) {
		unsigned long hash = str.length();
		for (int i = 0; i < str.length(); ++i) {
			hash = ((hash << 5) ^ (hash >> 27)) ^ str.at(i);
		}
		return hash;
	}
	int k;
	HashFunc *hashFunc;
public:
	Hash(int k) {
		this->k = k;
		hashFunc = new HashFunc[12];
		hashFunc[0] = &Hash::JSHash;
		hashFunc[1] = &Hash::RSHash;
		hashFunc[2] = &Hash::SDBMHash;
		hashFunc[3] = &Hash::DJBHash;
		hashFunc[4] = &Hash::DEKHash;
		hashFunc[5] = &Hash::BKDRHash0;
		hashFunc[6] = &Hash::BKDRHash1;
		hashFunc[7] = &Hash::BKDRHash2;
		hashFunc[8] = &Hash::BKDRHash3;
		hashFunc[9] = &Hash::BKDRHash4;
		hashFunc[10] = &Hash::BKDRHash5;
		hashFunc[11] = &Hash::BKDRHash6;
	}
	int* HashNums(const string& str, int m) {
		int *res = new int[k];
		for (int i = 0; i < k; i++) {
			res[i] = (this->*hashFunc[i])(str) % (unsigned)m;
		}
		return res;
	}
};



class BloomFilter {
private:
	int n, m;//n表示元素个数,m表示位串长度
	int k;//哈希函数个数
	Hash *hash;
	int *bits;
	void setBit(int x) {
		int pos = x >> 5;   //x / 32
		int addr = x - (pos << 5);//x % 32
		int &cell = bits[pos];
		cell |= 0x1 << addr;
	}
	bool getBit(int x) {
		int pos = x >> 5;  //x / 32
		int addr = x - (pos << 5);//x % 32
		int &cell = bits[pos];
		return cell & (0x1 << addr);
	}
public:
	BloomFilter(int n){
		int size;
		m = (double)n*1.44*7.643856;
		size = (m >> 5) + 1;
		k = log(2)*(double)m / (double)n;
		this->n = n;
		bits = new int[size];
		for (int i = 0; i < size; i++)bits[i] = 0;
		hash = new Hash(k);
	}
	void store(const string& s) {
		int *hashNum = hash->HashNums(s, m);
		for (int i = 0; i < k; ++i) {
			setBit(hashNum[i]);
		}
		delete hashNum;
	}

	bool in(const string& s) {
		int *hashNum = hash->HashNums(s, m);
		for (int i = 0; i < k; i++) {
			if (!getBit(hashNum[i]))
				return false;
		}
		return true;
	}
};

void inputHandle(BloomFilter *&bf) {
	int n;
	cin >> n;
	bf = new BloomFilter(n);
	string id;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		bf->store(id);
	}
}

void searchInFilter(BloomFilter &bf) {
	string id;
	while (cin >> id)
		cout << (bf.in(id) ? "true" : "false") << endl;	
}

int main()
{

	BloomFilter *bf;
	inputHandle(bf);
	searchInFilter(*bf);
	//system("pause");
	return 0;
}
/*
5 3
12345678912345678X
98765432198765432X
123456789A12345678
987654321B98765432
987654321C98765432
123456789A1234567C
987654321B98765412
123456789A12345678

5
12345678912345678X
98765432198765432X
123456789A12345678
987654321B98765432
987654321C98765432
123456789A12345678
*/