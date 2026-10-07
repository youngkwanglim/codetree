#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int n, k, l, a[34][34], r;
pair<int, int> robot[54];
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

void PrintRobot(){
    for(int i = 0; i < k; i++){
        cout << robot[i].first << " " << robot[i].second << '\n';
    }
    cout << "---------------\n";
}

void PrintA(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "---------------\n";
}

bool IsIn(int y, int x){
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

bool NotRobot(int y, int x){
    for(int i = 0; i < k; i++){
        if(robot[i].first == y && robot[i].second == x) return false;
    }
    return true;
}

void Move(){
    for(int i = 0; i < k; i++){
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n + 1, vector<int> (n + 1, -1));
        int sy = robot[i].first;
        int sx = robot[i].second;

        if(a[sy][sx] >= 1) continue; // 이건 어디서 정보를 얻을 수 있는거지?

        q.push({sy, sx});
        visited[sy][sx] = 0;
        while(q.size()){
            auto [y, x] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(IsIn(ny, nx) && visited[ny][nx] == -1 && a[ny][nx] != -1 && NotRobot(ny, nx)){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }

        int ty = sy, tx = sx, min_cnt = INT_MAX; // 갈수 없는 경우도 생각해야됨.
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(min_cnt > visited[i][j] && visited[i][j] > 0 && a[i][j] >= 1){ // 자기자신 금지, 먼지가 있는 곳이여야됨.
                    min_cnt = visited[i][j];
                    ty = i;
                    tx = j;
                }
            }
        }
        robot[i].first = ty;
        robot[i].second = tx;
    }
    // PrintRobot();
}

void Clean(){
    for(int i = 0; i < k; i++){
        int y = robot[i].first;
        int x = robot[i].second;

        int max_sum = -1;
        int td;
        for(int dir = 0; dir < 4; dir++){
            int psum = 0; 
            for(int d : {0, -1, 1}){
                int dd = (dir + d + 4) % 4;
                int ny = y + dy[dd];
                int nx = x + dx[dd];
                if(IsIn(ny, nx) && a[ny][nx] >= 1){
                    psum += min(a[ny][nx], 20); // 최대 20만 뺼 수 있음.
                }
                // psum += min(a[y][x], 20); // 어차피 중복이라 굳이 필요없
            }
            if(max_sum < psum){
                max_sum = psum;
                td = dir;
            }
        }

        for(int d : {0, -1, 1}){
            int dd = (td + d + 4) % 4;
            int ny = y + dy[dd];
            int nx = x + dx[dd];
            if(IsIn(ny, nx) && a[ny][nx] >= 1){
                a[ny][nx] -= min(a[ny][nx], 20);
            }
        }
        // cout << a[y][x] << " ";
        a[y][x] -= min(a[y][x], 20);
        // cout << a[y][x] << " ";
        // cout << '\n';
    }
    // PrintA();
}

void Plus(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] >= 1) a[i][j] += 5;
        }
    }
    // PrintA();
}

void Change(){
    int tmp_a[34][34] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] >= 1){
                for(int d = 0; d < 4; d++){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(IsIn(ny, nx) && a[ny][nx] == 0){
                        tmp_a[ny][nx] += a[i][j];
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += (tmp_a[i][j] / 10);
        }
    }

    // PrintA();
}

int Count(){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] >= 1) ret += a[i][j];
        }
    }
    return ret;
}

int main() {
    // Please write your code here.
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        int y, x;
        cin >> y >> x;
        robot[i].first = y;
        robot[i].second = x;
    }

    while(l--){
        // 1. 청소기 이동
        Move();

        // 2. 청소
        Clean();

        // 3. 먼지 축적
        Plus();

        // 4. 먼지 확산
        Change();
    
        // 5. 출력
        int r = Count();
        cout << r << '\n';
        // PrintA();
    }

    return 0;
}