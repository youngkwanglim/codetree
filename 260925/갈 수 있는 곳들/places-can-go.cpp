#include <iostream>
#include <queue>
using namespace std;
int n, k, visited[104][104], a[104][104], y, x, ret; 
queue<pair<int, int>> q;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

bool CanGo(int y, int x){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] == 1) return false;
    return true;
}

void BFS(){
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        // cout << y << ", " << x << '\n';
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(CanGo(ny, nx)){
                // cout << ny << " " << nx << '\n';
                ret++;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        cin >> y >> x;
        if(CanGo(y, x)){
            visited[y][x] = 1;
            ret++;
            q.push({y, x});
        }
    }

    BFS();
    cout << ret;
    return 0;
}