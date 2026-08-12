#include <iostream>
using namespace std;
//A는 65 Z가 90 총 26개
char c = 'A'; 

int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0}, n, m, y, x, dir, a[104][104], ny, nx;

bool IsIn(int y, int x){
    return (0 <= y && y < n && 0 <= x && x < m);
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    for(int i = 1; i <= n * m; i++){
        //cout << ny << " " << nx << '\n';
        a[y][x] = i;
        ny = y + dy[dir];
        nx = x + dx[dir];
        if(!IsIn(ny, nx) || a[ny][nx]){
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        y = ny, x = nx;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout << a[i][j] << ' ';
            cout << char(65 + ((a[i][j] - 1) % 26)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}