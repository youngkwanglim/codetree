#include <iostream>
using namespace std;
int n, k, ret, a[504][504], psum[504][504];

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j]; 
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // cout << psum[i][j] << " ";
        }
        //cout << '\n';
    }

    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j <= n - k; j++){
            int tmp = psum[i + k][j + k] - psum[i][j + k] - psum[i + k][j] + psum[i][j];
            ret = max(ret, tmp);
        }
    }
    cout << ret;
    return 0;
}