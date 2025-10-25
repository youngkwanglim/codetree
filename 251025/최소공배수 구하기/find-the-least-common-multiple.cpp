#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1;

void go(int n, int m){
    int gcd = 0;
    for(int i = 1; i <= min(n,m); i++){
        if(n % i == 0 && m % i == 0){
            gcd = i;
        }
    }
    cout << n * m / gcd;
}

int main() {
    cin >> n >> m;

    // Please write your code here.
    go(n,m);

    return 0;
}