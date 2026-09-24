#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[30][30], visited[30][30], cnt;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};
vector<int> v;

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool CanGo(int y, int x){
    if(!IsIn(y, x)) return false;
    if(visited[y][x] || a[y][x] == 0) return false;
    return true;
}

void DFS(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(CanGo(ny, nx)){
            cnt++;
            visited[ny][nx] = 1; 
            DFS(ny, nx);
        }
    }
}

int main() {
    // Please write your code here.
    //dfs로 돌면서 마을 인원 저장하고, 오름차순 정렬해주기.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt = 0;
            if(a[i][j] == 1 && !visited[i][j]){
                visited[i][j] = 1;
                cnt++;
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}