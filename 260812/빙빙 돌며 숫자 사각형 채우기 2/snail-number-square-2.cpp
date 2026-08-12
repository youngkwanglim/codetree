#include <iostream>
using namespace std;
int n, m, a[104][104];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1}, y, x, dir = 0;

bool IsIn(int y, int x){
    return (0 <= y && y < n && 0 <= x && x < m);
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++){
        //cout << "y는 " << y << ", x는 " << x << '\n';
        a[y][x] = i;
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 범위를 벗어나거나 이미 차있으면 방향 전환 (dir + 1) % 4
        if(!IsIn(ny, nx) || a[ny][nx]){
            //cout << i << "일 때 dir = " << dir << "\n";
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        y = ny;
        x = nx;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}