#include <iostream>
using namespace std;
int n, k, a[1004], ret, psum[1004];

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){ // 구간 크기 정하기
        for(int j = 0; j <= n - i; j++){
            int tmp = psum[j + i] - psum[j];
            if(tmp == k) ret++;
        }
    }

    cout << ret;

    return 0;
}