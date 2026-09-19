#include <iostream>
#include <list>
using namespace std;
int n, m;
list<char> v;


int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        v.push_back(c);
    }

    auto it = v.end();
    for(int i = 0; i < m; i++){
        char c;
        cin >> c;
        if(c == 'L'){
            if(it != v.begin()) it--;
        }
        if(c == 'R'){
            if(it != v.end()) it++;
        }
        if(c == 'D'){
            if(it != v.end()) it = v.erase(it);
        }
        if(c == 'P'){
            char tmp;
            cin >> tmp;
            v.insert(it, tmp);
        }
    }

    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it;
    }
    return 0;
}