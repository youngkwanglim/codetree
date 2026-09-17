#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> st;
string s;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        int tmp = 0;
        if(s == "push"){
            cin >> tmp;
            st.push(tmp);
        }
        if(s == "pop"){
            tmp = st.top();
            cout << tmp << '\n';
            st.pop();
        }
        if(s == "size"){
            cout << st.size() << '\n';
        }
        if(s == "empty"){
            if(st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n'; 
        }
        if(s == "top"){
            cout << st.top() << '\n';
        }
    }
    return 0;
}