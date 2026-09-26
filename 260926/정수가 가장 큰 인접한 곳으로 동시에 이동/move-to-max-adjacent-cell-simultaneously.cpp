#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t, a[24][24], y, x, ball[24][24], tmp_ball[24][24], ret;
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

void Move(int y, int x){
    int tmp = -1;
    int real_ny = 0;
    int real_nx = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(IsIn(ny, nx) && a[ny][nx] > tmp){
            tmp = a[ny][nx];
            real_ny = ny;
            real_nx = nx;
        }
    }
    // cout << real_ny << " " << real_nx << '\n';
    tmp_ball[real_ny][real_nx]++;
}

void UpdateBall(){
    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            if(tmp_ball[i][j] > 1) tmp_ball[i][j] = 0;
        }
    }
}

void CopyBall(){
    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            ball[i][j] = tmp_ball[i][j];
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> y >> x;
        y--; x--;
        ball[y][x] = 1;
    }

    while(t--){
        for(int i = 0; i < n; i++){
            for(int j= 0; j < n; j++){
                if(ball[i][j]) {
                    Move(i, j);
                }
            }
        }
        UpdateBall();
        CopyBall();
        fill(&tmp_ball[0][0], &tmp_ball[0][0] + 24 * 24, 0);
    }

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            if(ball[i][j]) ret++;
        }
    }
    cout << ret;
    return 0;
}