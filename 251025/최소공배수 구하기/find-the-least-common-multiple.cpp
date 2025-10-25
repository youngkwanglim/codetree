#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1;

int main() {
    cin >> n >> m;

    // Please write your code here.
    for(int i = 1; i <= 10000000; i++){
        if(i % n == 0 && i % m == 0){
            ret = i;
            break;
        }
    }
    cout << ret;

    return 0;
}