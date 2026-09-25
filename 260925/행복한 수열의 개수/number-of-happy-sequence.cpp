#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[104][104], ret, visited[104];

void CheckHappry(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }    
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // 가로 확인
    for(int i = 0; i < n; i++){
        int tmp = a[i][0];
        int p_count = 1;
        for(int j = 1; j < n; j++){
            if(tmp == a[i][j]){
                p_count++;
                if(p_count == m){
                    ret++;
                    break;
                }
            }
            else{
                tmp = a[i][j];
                p_count = 1;
            }
        }
    }

    // 세로 확인
    for(int i = 0; i < n; i++){
        int tmp = a[0][i];
        int p_count = 1;
        for(int j = 1; j < n; j++){
            if(tmp == a[j][i]){
                p_count++;
                if(p_count == m){
                    ret++;
                    break;
                }
            }
            else{
                tmp = a[j][i];
                p_count = 1;
            }
        }
    }

    if(m == 1) cout << n * 2;
    else cout << ret;
    return 0;
}