#include <iostream>
using namespace std;
int n, ret, t, a[104][104], dir;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;

bool IsIn(int y, int x){
    return (0 <= y && y < n && 0 <= x && x < n);
}

int main() {
    // Please write your code here.
    cin >> n >> t >> s;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int x = n / 2;
    int y = n / 2;
    ret += a[y][x];

    // L은 왼쪽으로 90도
    // R은 오른쪽으로 90도
    // F는 전진
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        else if(s[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else{
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(!IsIn(ny, nx)){
                continue;
            }
            y = ny;
            x = nx;
            ret += a[ny][nx];
        }
    } 

    cout << ret << '\n';

    return 0;
}