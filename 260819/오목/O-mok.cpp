#include <iostream>
using namespace std;
int a[24][24], ret, y, x;

int main() {
    // Please write your code here.
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <=19; j++){
            cin >> a[i][j];
        }
    }

    // for(int i = 1; i <= 19; i++){
    //     for(int j = 1; j <=19; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // 만약 왼쪽으로 갔으면 쭉 왼쪽으로 가버리고
    // 오른쪽이면 쭉 오른쪽
    // 왼쪽 대각선이면 쭉 대각선

    // 맨위에서부터 한점씩 저 3가지 경우의 수를 한번해보기.
    // 1~15칸 까지 체크하면 됨. 15~19
    // 검정이 이기면 1, 흰색이 이기면 2
    // cout << a[4][8] << '\n';

    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= 15; j++){
            if(a[i][j] != 0 && a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j + 2] == a[i][j + 3] && a[i][j + 3] == a[i][j + 4]){
                if(a[i][j] == 1) ret = 1, y = i, x = j + 2;  
                if(a[i][j] == 2) ret = 2, y = i, x = j + 2; 
                //cout << i << " " << j << '\n';
            }
            if(a[j][i] != 0 && a[j][i] == a[j + 1][i] && a[j + 1][i] == a[j + 2][i] && a[j + 2][i] == a[j + 3][i] && a[j + 3][i] == a[j + 4][i]){
                if(a[j][i] == 1) ret = 1, y = j + 2, x = i;  
                if(a[j][i] == 2) ret = 2, y = j + 2, x = i; 
                // cout << i << " " << j << '\n';
            }
            if(a[i][j] != 0 && a[i][j] == a[i+ 1][j + 1] && a[i][j] == a[i+ 2][j + 2] && a[i][j] == a[i+ 3][j + 3] && a[i][j] == a[i + 4][j + 4]){
                if(a[i][j] == 1) ret = 1, y = i + 2, x = j + 2; 
                if(a[i][j] == 2) ret = 2, y = i + 2, x = j + 2; 
            }
            if(a[i][20 - j] != 0 && a[i][20 - j] == a[i + 1][19 - j] && a[i][20 - j] == a[i + 2][18 - j] && a[i][20 - j] == a[i + 3][17 - j] && a[i][20 - j] == a[i + 4][16 - j]){
                if(a[i][20 - j] == 1) ret = 1, y = i + 2, x = 20 - j - 2; 
                if(a[i][20 - j] == 2) ret = 2, y = i + 2, x = 20 - j - 2; 
            }
        }
    }

    // for(int i = 1; i <= 15; i++){
    //     if(a[i][i] != 0 && a[i][i] == a[i + 1][i + 1] && a[i + 1][i + 1] == a[i + 2][i + 2] && a[i + 2][i + 2] == a[i + 3][i + 3] && a[i + 3][i + 3] == a[i + 4][i + 4]){
    //         if(a[i][i] == 1) ret = 1, y = i + 2, x = i + 2;  
    //         if(a[i][i] == 2) ret = 2, y = i + 2, x = i + 2;
    //         // cout << i << " " << i << '\n';
    //     }
    // }

    if(ret == 0) cout << ret;
    else{
        cout << ret << '\n';
        cout << y << " " << x;
    }
    return 0;
}