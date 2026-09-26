#include <iostream>
using namespace std;
int n, m, a[24][24], b[24][24];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

void FindNumber(int num){
    int tmp = 0;
    int change_y = 0;
    int change_x = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 여기서부터 최대값 찾아서 바꿔줘야됨.
            if(a[i][j] == num){
                for(int k = 0; k < 8; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(IsIn(ny, nx) && tmp < a[ny][nx]){
                        tmp = a[ny][nx];
                        change_y = ny;
                        change_x = nx;
                    }
                }

                a[change_y][change_x] = a[i][j];
                a[i][j] = tmp;
                return;
            }
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

    while(m--){
        for(int i = 1; i <= n * n; i++){ // 20 * 20 * 20 * 100
            FindNumber(i);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}