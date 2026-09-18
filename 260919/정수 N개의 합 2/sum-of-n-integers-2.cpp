#include <iostream>
#include <climits>
using namespace std;
int n, k;
int a[100004], psum[100004], ret = -INT_MAX;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){    // 1부터 n까지 차있음.
        psum[i] = psum[i - 1] + a[i - 1];
        //cout << psum[i] << ' ';
    }

    for(int i = 1; i <= n - k + 1; i++){
        ret = max(ret, psum[i + k] - psum[i]);
    }
    cout << ret;
    return 0;
}