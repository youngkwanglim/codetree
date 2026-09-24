#include <iostream>
using namespace std;
int n, m, k, a[54][54], ret = -1, visited[54][54], cnt;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool CanGo(int y, int x, int k){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] <= k) return false;
    return true;
}

void DFS(int y, int x, int k){
    // int tmp = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(CanGo(ny, nx, k)){
            visited[ny][nx] = 1;
            DFS(ny, nx, k);
        }
    }
    // return tmp;
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    //k를 올려가면서 안전영역 수가 비어야됨.
    for(int h = 1; h <= 100; h++){
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > h && !visited[i][j]){
                    cnt++;
                    visited[i][j] = 1;
                    DFS(i, j, h);
                }
            }
        }
        if(cnt > ret){
            ret = cnt;
            k = h;
        }
    }

    cout << k << ' ' << ret << '\n';
    return 0;
}