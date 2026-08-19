#include <iostream>
using namespace std;
int n, ret, a[24][24];

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
            for(int k = i; k < n; k++){
                for(int l = 0; l < n - 2; l++){
                    if(i == k && j + 2 >= l) continue;
                    int tmp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[k][l] + a[k][l + 1]+ a[k][l + 2];

                    //cout << tmp << '\n';
                    ret = max(tmp, ret);
                }
            }
        }
    }

    cout << ret;
    
    return 0;
}