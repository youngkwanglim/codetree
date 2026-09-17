#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n;
string s;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        int tmp = 0;
        if(s == "push"){
            cin >> tmp;
            q.push(tmp);
        }
        if(s == "pop"){
            cout << q.front() << "\n";
            q.pop();
        }
        if(s == "size"){
            cout << q.size() << "\n";
        }
        if(s == "empty"){
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        if(s == "front"){
            cout << q.front() << '\n';
        }
    }
    return 0;
}