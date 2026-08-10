#include <iostream>
using namespace std;
int n, m, a[104][104], x, y, dx[4] = {1, 0 , - 1, 0}, dy[4] = {0, 1, 0, -1}, dir;

bool InRange(int x, int y){
    return (0 <= x && x < m && 0 <= y && y < n);
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    a[0][0] = 1;
    x = 0;
    y = 0;

    for(int i = 2; i <= n * m; i++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!InRange(nx, ny) || a[ny][nx]){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        //cout << ny << ' ' << nx << '\n';
        x = nx;
        y = ny;
        a[y][x] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        } 
        cout << '\n';
    }

    return 0;
}