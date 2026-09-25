#include <iostream>
using namespace std;
int n, y, x, a[104][104];
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, nr, nc;

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

int main() {
    // Please write your code here.
    cin >> n >> y >> x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    cout << a[y][x] << " ";
    while(true){
        int flg = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(IsIn(ny, nx) && a[ny][nx] > a[y][x]){
                cout << a[ny][nx] << " ";
                y = ny;
                x = nx;
                flg = 0;
                break;
            }
        }
        if(flg) break;
    }
    return 0;
}