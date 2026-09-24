#include <iostream>
using namespace std;
int n, a[104][104], ret, max_block, visited[104][104];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool CanGo(int y, int x, int k){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] != k) return false;
    return true; 
}

int DFS(int y, int x, int k){
    int tmp = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(CanGo(ny, nx, k)){
            visited[ny][nx] = 1;
            tmp += DFS(ny, nx, k);
        }
    }
    return tmp;
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // dfs로 돌면서 같은 수인지 체크하고 맞으면 cnt 증가 시키고 r개 이상이면 ret++;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                int k = a[i][j];
                int cnt = DFS(i, j, k); // 4개 이상이면 터짐.
                max_block = max(max_block, cnt);
                if(cnt >= 4) {
                    ret++;
                }
            }
        }
    }

    cout << ret << " " << max_block;
    return 0;
}