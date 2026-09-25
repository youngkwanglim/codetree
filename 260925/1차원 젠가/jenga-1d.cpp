#include <iostream>
#include <deque>
using namespace std;
int n, a[104], b[104], c[104], s1, e1, s2, e2, tmp, cnt;
// vector<int> v1, v2, v3;
deque<int> dq1, dq2, dq3;


int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        dq1.push_back(tmp);
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    s1--; e1--; s2--; e2--;

    for(int i = 0; i < dq1.size(); i++){
        if(s1 > i || i > e1) dq2.push_back(dq1[i]);
    }
    
    for(int i = 0; i < dq2.size(); i++){
        if(s2 > i || i > e2) dq3.push_back(dq2[i]);
    }

    cout << dq3.size() << '\n';
    for(int i = 0; i < dq3.size(); i++){
        cout << dq3[i] << '\n';
    }
    return 0;
}