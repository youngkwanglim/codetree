#include <bits/stdc++.h>
using namespace std;

int n, m, ret;

int main() {
    cin >> n >> m;

    // Please write your code here.
    for(int i = 100; i > 0; i--){
        if(i % n == 0 && i % m == 0){
            ret = i;
        }
    }
    cout << ret;

    return 0;
}