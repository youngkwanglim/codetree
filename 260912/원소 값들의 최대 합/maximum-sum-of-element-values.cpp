#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[104], ret, cut;

int go(int i){
    if(cut == m) return 0;
    cut++;
    // cout << a[i] << " ";
    return a[i] + go(a[i]);
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        cut = 0;
        ret = max(ret, go(i));
    }

    cout << ret;
    return 0;
}