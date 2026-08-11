#include <iostream>
using namespace std;
int n, m, a[104][104], x, y, ret;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}; 

bool IsIn(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        a[x][y] = 1;
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(IsIn(nx, ny) && a[nx][ny]) cnt++;
        }
        //cout << cnt << '\n' << '\n';
        if(cnt == 3) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}