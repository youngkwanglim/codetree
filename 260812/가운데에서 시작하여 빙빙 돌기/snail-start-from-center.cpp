#include <iostream>
using namespace std;
int n, dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0}, dir, cnt, step = 1, a[104][104], flg;

bool IsIn(int y, int x){
    return (0 <= y && y < n && 0 <= x && x < n);
}

int main() {
    // Please write your code here.
    cin >> n;
    int x = n / 2;
    int y = n / 2;
    a[y][x] = 1;

    // 중앙에서 부터 1, 1, 2, 2, 3, 3 이렇게 늘어나는데 이때마다 방향 바꿔주면서 이동하면 될거같은데.
    
    while(true){
        if(flg) break;
        //if(cnt > n * n) break;
        //int ny, nx;
        for(int i = 0; i < step; i++){
            //cnt++;
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            //cout << ny << " " << nx << '\n';
            if(!IsIn(y, x)){
                flg = 1;
                break;
            }
            a[ny][nx] = a[y][x] + 1;
            y = ny, x = nx;
            //if(cnt % 2 == 1) step++;
        }
        dir = (dir + 1) % 4;

        cnt++;
        //cout << "cnt는 " << cnt << '\n';
        if(cnt % 2 == 0) step++;

        // if(cnt % 2 == 1){
        //     y = x + dy[dir];
        //     x = y + dy[dir];
        // }
        // else{
        //     y = x + dy[dir];
        //     x = y + dy[dir];
        //     step++;
        // }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}