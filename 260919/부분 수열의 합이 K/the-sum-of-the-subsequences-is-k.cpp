#include <iostream>
using namespace std;
int n, k, a[1004], ret, psum[1004];

int GetSum(int i, int j){
    return psum[j] - psum[i - 1];
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){ 
        for(int j = i; j <= n; j++){
            if(GetSum(i, j) == k) ret++;
        }
    }

    cout << ret;

    return 0;
}