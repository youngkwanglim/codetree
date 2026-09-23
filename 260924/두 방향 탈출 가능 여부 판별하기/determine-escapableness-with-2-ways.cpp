#include <iostream>
using namespace std;
int n, m, a[104][104], visited[104][104];
int dy[2] = {1, 0}, dx[2] = {0, 1};

bool InRange(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < m;
}


bool CanGo(int y, int x){
    if(!InRange(y, x)) return false;
    if(visited[y][x] || a[y][x] == 0) return false;
    return true;
}

void DFS(int y, int x){
    for(int i = 0; i < 2; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(CanGo(ny, nx)) {
            visited[ny][nx] = 1;
            DFS(ny, nx);
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    visited[0][0] = 1;
    DFS(0, 0);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(visited[n - 1][m - 1]) cout << 1;
    else cout << 0;
    return 0;
}