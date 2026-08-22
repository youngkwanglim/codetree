#include <iostream>

using namespace std;

int n, m, a[104], b[104], ret;

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for(int i = 0; i < n - m + 1; i++){

        int b_check[m] = {};  // 여기만 수정
        int flg = 0;

        for(int j = i; j < i + m; j++){

            for(int k = 0; k < m; k++){

                if(b_check[k] == 0 && a[j] == b[k]){
                    b_check[k] = 1;
                    break;  // 이것도 추가하는 것을 추천
                }
            }
        }

        for(int k = 0; k < m; k++){

            if(b_check[k] == 0){
                flg = 1;
                break;
            }
        }

        if(flg == 0) ret++;
    }

    cout << ret;

    return 0;
}