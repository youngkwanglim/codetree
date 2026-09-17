#include <iostream>
#include <stack>
using namespace std;
string s;
stack<char> st;
int flg = 1;

int main() {
    // Please write your code here.
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(st.empty()) {
                flg = 0;
                break;  
            }
            st.pop();
            continue;
        }
    }
    if(st.empty() && flg) cout << "Yes";
    else cout << "No";
    return 0;
}