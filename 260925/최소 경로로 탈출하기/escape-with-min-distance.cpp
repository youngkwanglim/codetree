#include <iostream>
#include <queue>
using namespace std;
int n, m, a[104][104], visited[104][104], step[104][104], y, x;
queue<pair<int, int>> q;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

void Push(int y, int x, int cnt){
    visited[y][x] = 1;
    step[y][x] = cnt;
    q.push({y, x});
}

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool Cango(int y, int x){
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
            if(Cango(ny, nx)){
                Push(ny, nx, step[y][x] + 1);
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

    Push(0, 0, 0);
    BFS();

    if(step[n - 1][m - 1] == 0) cout << -1;
    else cout << step[n - 1][m - 1];
    return 0;
}