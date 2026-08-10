#include <iostream>
using namespace std;
int n, a[104][104], ret, dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};


int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if((0 <= nx && nx < n && 0 <= ny && ny < n) && a[nx][ny] == 1) cnt++;
            }
            if(cnt >= 3) ret++;
        }
    }

    cout << ret;
    return 0;
}