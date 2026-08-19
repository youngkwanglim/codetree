#include <iostream>
using namespace std;
int a[24][24], ret, y, x;
int dy[4] = {0, 1, 1, 1}, dx[4] = {1, 0, 1, -1};

bool IsIn(int y, int x){
    return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

int main() {
    // Please write your code here.
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <=19; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= 19; j++){

            if(a[i][j] == 0) continue;

            for(int k = 0; k < 4; k++){
                int cnt = 1;
                int cury = i;
                int curx = j;

                while(true) {
                    int ny = cury + dy[k];
                    int nx = curx + dx[k];
                    if(!IsIn(ny, nx)) break;
                    if(a[i][j] != a[ny][nx]) break; 
                    cnt++;
                    curx = nx;
                    cury = ny;

                    if(cnt == 5){
                        ret = a[i][j];
                        y = i + dy[k] * 2;
                        x = j + dx[k] * 2;
                        break;
                    }
                }
            }
        }
    }

    if(ret == 0) cout << ret;
    else {
        cout << ret << '\n';
        cout << y << " " << x;
    }
    return 0;
}