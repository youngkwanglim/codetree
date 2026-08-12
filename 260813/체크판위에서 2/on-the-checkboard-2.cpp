#include <iostream>
using namespace std;
int r, c, ret;
char a[20][20];

int main() {
    // Please write your code here.
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }

    // 모든 위치 2개를 조합해서 첫번째랑 두번째랑 세번째가 각각 색깔 다른지 체크하면 될듯함
    for(int i = 1; i < r - 1; i++){
        for(int j = 1; j < c - 1; j++){
            for(int k = i + 1; k < r - 1; k++){
                for(int l = j + 1; l < c - 1; l++){
                    if(a[0][0] != a[i][j] && a[i][j] != a[k][l] && a[k][l] != a[r - 1][c - 1]) ret++;
                }
            }
        }
    }

    cout << ret << '\n';
    return 0;
}