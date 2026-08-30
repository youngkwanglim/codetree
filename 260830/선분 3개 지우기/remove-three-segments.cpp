#include <iostream>
using namespace std;
int n, a[14][2], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    // 선분 3개를 고름. 그거 빼고 체크를 함.
    // 그리고 체크한게 2개 이상 있으면 그 선분확인은 제외임.
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                //cout << i << " " << j << " " << k << '\n';

                int check[104] = {};
                int flg = 1;
                for(int l = 0; l < n; l++){
                    if(l != i && l != j && l != k){
                        for(int m = a[l][0]; m <= a[l][1]; m++){
                            check[m]++;
                        }
                    }
                }

                for(int l = 0; l <= 100; l++){
                    if(check[l] >= 2) {
                        flg = 0;
                        break;
                    }
                }
                if(flg) {
                    ret++;
                    //cout << i << " " << j << " " << k << '\n';
                }
            }
        }
    }

    cout << ret;
    return 0;
}