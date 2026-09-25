#include <iostream>
using namespace std;
int n, a[204][204], visited[204][204], y, x;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool CanGo(int y, int x){
    return !visited[y][x] && IsIn(y, x);
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cin >> y >> x;
    y--; x--;
    visited[y][x] = 1;

    for(int i = 1; i < a[y][x]; i++){
        for(int j = 0; j < 4; j++){
            int ny = y + dy[j] * i;
            int nx = x + dx[j] * i;
            if(CanGo(ny, nx)){
                visited[ny][nx] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        int tmp[n] = {};
        int tmp_idx = 0;
        for(int j = n - 1; j >= 0; j--){
            if(!visited[j][i]){
                tmp[tmp_idx++] = a[j][i];
            }
        }
        for(int j = n - 1; j >= 0; j--){
            a[j][i] = tmp[n - 1 - j];
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