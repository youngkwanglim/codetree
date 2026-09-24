#include <iostream>
#include <queue>
using namespace std;
int n, m, a[104][104], visited[104][104];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1}, y, x;
queue<pair<int , int>> q;

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool CanGo(int y, int x){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] == 0) return false;
    return true;
}

void BFS(){
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(CanGo(ny, nx)){
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
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
    q.push({0, 0});
    BFS();

    if(visited[n - 1][m - 1]) cout << 1;
    else cout << 0;
    return 0;
}