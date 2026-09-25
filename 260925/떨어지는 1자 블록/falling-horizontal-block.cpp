#include <iostream>
using namespace std;
int n, m, a[104][104], k;

int main() {
    // Please write your code here.
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n + 1; i++){
        int flg = 0;
        for(int j = k; j <= k + m - 1; j++){
            if(a[i][j] || i == n + 1){
                flg = 1;
                break;
            }
        }
        if(flg){
            for(int j = k; j <= k + m - 1; j++){
                a[i - 1][j] = 1;
            }
            break;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " "; 
        }
        cout << '\n';
    }

    return 0;
}