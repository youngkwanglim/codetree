#include <iostream>
#include <queue>
using namespace std;
int n, a[104][104], r, c, visited[104][104], y, x, max_value, k, bar;
queue<pair<int, int>> q;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

bool CanGo(int y, int x, int h){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] >= h) return false;
    return true;
}

void Change(int y, int x){
    if(a[y][x] > max_value){
        r = y;
        c = x;
        max_value = a[y][x];
    }
    else if(a[y][x] == max_value){
        if(y == r && x < c){
            c = x;
        }
        if(y < r){
            r = y;
            c = x;
        }
    }
}

void bfs(){
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        // if(a[y][x] > max_value){
        //     r = y;
        //     c = x;
        //     h = a[y][x];
        // }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(CanGo(ny, nx, bar)){
                visited[ny][nx] = 1;
                Change(ny, nx);
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
    cin >> r >> c;

    // 무식하게 푸는 법은 그냥 순회하면서 나보다 작은게 있으면 걔를 넣어. 이건 자기보다 크면 막히니까 안되네.
    // dfs는 막히는걸 늦게 아니까 bfs로?
    for(int i = 0; i < k; i++){
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        q.push({r, c});
        visited[r][c] = 1;
        bar = a[r][c];
        max_value = 0;
        bfs();
    }

    cout << r << " " << c;

    return 0;
}