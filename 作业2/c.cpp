#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
template<class T>
class Stack {
    T data[200];
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
};
class Solution {
public:
    string decodeString(string s) {
        string res;
        res.reserve(1000);
 
        Stack<int> nums;
        Stack<string> strs;
        string tmp_str;
        int tmp_num=0;
        string::iterator ch = s.begin();
        while (ch != s.end()) {
            if (isdigit(*ch)) {
                 
                while (isdigit(*ch)) {
                    tmp_num = tmp_num * 10 + *ch - '0';
                    ch++;
                }
            }
            else if (isalpha(*ch)) {                
                while (ch!=s.end()&&isalpha(*ch)) {
                    tmp_str += *ch;
                    ch++;
                }
            }
            else if (*ch == '[') {
 
                nums.push(tmp_num); 
                tmp_num = 0;
                strs.push(tmp_str);
                tmp_str.clear();
                 
                 
                ch++;
            }
            else if (*ch == ']') {
                if (!strs.empty()) {
                    tmp_str = strs.top() + extend_str(tmp_str, nums.top());
                    strs.pop();
                    nums.pop();
                }
                else if (!nums.empty()) {
                    tmp_str = extend_str(tmp_str, nums.top());
                    nums.pop();
                }
 
                if(nums.empty()) {
                    res += tmp_str;
                    tmp_str.clear();
                }
                ch++;
            }
        }
        res += tmp_str;
        return res;
    }
private:
    string extend_str(string element, int n) {
        string s;
        for (int i = 0; i < n; i++)
            s.append(element);
        return s;
    }
 
};
int main(){
    string buf;
    cin>>buf;
    Solution s;
    cout<<s.decodeString(buf);
     
    return 0;
}