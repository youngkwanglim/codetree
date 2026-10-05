#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, r, c, d, a[54][54], visited[54][54], y, x, cnt, total;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

void printBoard(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

vector<vector<int>> bfs(int sy, int sx){
    vector<vector<int>> dist(n + 1, vector<int> (n + 1, -1));
    queue<pair<int,int>> q;
    dist[sy][sx] = 0;
    q.push({sy, sx});
    while(q.size()){
        int y = 0, x = 0;
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(IsIn(ny, nx) && a[ny][nx] == 0 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return dist;
}

void go(){
    while(cnt < total){
        // tie(y, x) = q.front();
        // q.pop();
        // cout << y << " " << x << '\n';

        // 인접 탐험
        while(true){
            int flg = 1;
            for(int delta : {0, 1, 3, 2}) {
                int nd = (d + delta) % 4;
                int ny = y + dy[nd];
                int nx = x + dx[nd];
                if(IsIn(ny, nx) && !visited[ny][nx] && a[ny][nx] == 0){
                    visited[ny][nx] = 1;
                    d = nd; x = nx; y = ny;
                    flg = 0;
                    cnt ++;
                    cout << y << ' ' << x << "\n";
                    break;
                }
            }
            if(flg) break;
        }
        if(cnt >= total) break;
        
        auto dist_from = bfs(y, x); 

        // 미방문 바다 칸 중 최소 거리 칸 선택
        int ty = -1, tx = -1, min_dist = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] != 0 || visited[i][j] || dist_from[i][j] == -1) continue;
                if(min_dist == -1 || dist_from[i][j] < min_dist){
                    ty = i; tx = j; min_dist = dist_from[i][j];
                }
            }
        }

        // 경로 추적에 필요한 거리맵
        auto dist_to = bfs(ty, tx);
        while(y != ty || x != tx){
            for(int dir : {1, 2, 3, 0}){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(IsIn(ny, nx) && a[ny][nx] == 0 && dist_to[ny][nx] == dist_to[y][x] - 1){
                    y = ny; x = nx; d = dir;
                    break;
                }
            }
        }
        visited[y][x] = 1;
        cnt++;
        cout << y << " " << x << '\n';
    }
}

int main() {
    // Please write your code here.
    cin >> n >> y >> x >> d;
    int dir_map[4] = {0, 2, 1, 3};
    d--;
    d = dir_map[d];



    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) total++;
        }
    }

    visited[y][x] = 1;
    cnt++;
    cout << y << ' ' << x << '\n';
    go();

    // printBoard();
    return 0;
}