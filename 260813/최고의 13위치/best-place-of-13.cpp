#include <iostream>
using namespace std;
int a[24][24], ret, n;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 2; j++){
            ret = max(ret, a[i][j] + a[i][j + 1] + a[i][j + 2]);
            //cout << a[i][j] << a[i][j + 1] << a[i][j + 2] << '\n';
        }
    }

    cout << ret;
    return 0;
}