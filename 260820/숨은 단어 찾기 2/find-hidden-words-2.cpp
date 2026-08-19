#include <iostream>
using namespace std;
int n, m, ret;
char c[54][54];
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[8] = {0, -1, - 1, -1, 0, 1, 1, 1};

bool IsIn(int y, int x){
    return 0 <= y && y <= n && 0 <= x && x <= m;
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(c[i][j] != 'L') continue;

            for(int k = 0; k < 8; k++){
                int cury = i;
                int curx = j;
                int cnt = 1;

                for(int l = 1; l <= 2; l++){
                    cnt = 1;
                    int ny = cury + dy[k];
                    int nx = curx + dx[k];

                    if(!IsIn(ny, nx)) break;
                    if(c[ny][nx] != 'E') break;
                    cury = ny;
                    curx = nx;
                    cnt++;
                }
                //cout << i << " " << j << " " << k << '\n';
                if(cnt == 2) ret++; // LEE 완성
            }

            
        }
    }

    cout << ret;

    return 0;
}