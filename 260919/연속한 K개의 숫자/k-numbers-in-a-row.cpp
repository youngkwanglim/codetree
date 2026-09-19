#include <iostream>
#include <climits>
using namespace std;
int n, k, b, a[100004], ret = INT_MAX, psum[100004];

int main() {
    // Please write your code here.
    cin >> n >> k >> b;
    for(int i = 0; i < b; i++){
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }

    for(int i = 1; i <= n; i++){
        psum[i] = psum[i - 1] + a[i];
    }

    for(int i = 0; i <= n - k; i++){
        int cnt = psum[i + k] - psum[i];
        ret = min(ret, cnt);
    }
    cout << ret;
    return 0;
}