#include <iostream>
#include <queue>
using namespace std;
int n, sy, sx, ey, ex, y, x, visited[104][104], step[104][104];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> q;

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

bool CanGo(int y, int x){
    if(!IsIn(y, x)) return false;
    if(visited[y][x]) return false;
    return true;
}

void Push(int y, int x, int cnt){
    visited[y][x] = 1;
    step[y][x] = cnt;
    q.push({y, x});
}

void BFS(){
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        if(y == ey && x == ex){
            cout << step[ey][ex];
            return;
        }
        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(CanGo(ny, nx)){
                Push(ny, nx, step[y][x] + 1);
            }
        }
    }
    cout << -1;
}


int main() {
    // Please write your code here.
    cin >> n;
    cin >> sy >> sx >> ey >> ex;

    q.push({sy, sx});
    BFS();    // 제자리로 돌아오면 멈추기.
    return 0;
}