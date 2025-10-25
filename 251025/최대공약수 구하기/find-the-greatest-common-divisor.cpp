#include <bits/stdc++.h>

using namespace std;

int n, m, ret = 1;

int main() {
    cin >> n >> m;

    // Please write your code here.
    for(int i = 2; i <=100; i++){
        if(n % i == 0 && m % i == 0){
            ret = i;
        }
    }
    cout << ret;

    return 0;
}