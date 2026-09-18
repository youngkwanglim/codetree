#include <iostream>
#include <deque>
using namespace std;
int n;
deque<int> dq;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int tmp;
        if(s == "push_back"){
            cin >> tmp;
            dq.push_back(tmp);
        }
        if(s == "push_front"){
            cin >> tmp;
            dq.push_front(tmp);
        }
        if(s == "pop_front"){
            tmp = dq.front();
            cout << tmp << '\n';
            dq.pop_front();
        }
        if(s == "pop_back"){
            tmp = dq.back();
            cout << tmp << '\n';
            dq.pop_back();
        }
        if(s == "size"){
            cout << dq.size() << '\n';
        }
        if(s == "empty"){
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if(s == "front"){
            cout << dq.front() << '\n';
        }
        if(s == "back"){
            cout << dq.back() << '\n';
        }
    }
    return 0;
}