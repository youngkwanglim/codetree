#include <iostream>
using namespace std;
int n, a[24][24], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= n - 3; i++){
        for(int j = 0; j <= n - 3; j++){
            int coin_sum = 0;
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    coin_sum += a[i + k][j + l];
                }
            }
            ret = max(ret, coin_sum);
        }
    }

    cout << ret;
    return 0;
}