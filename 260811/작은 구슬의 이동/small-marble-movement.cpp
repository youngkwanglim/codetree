#include <iostream>
using namespace std;
int n, t, x, y, c, dx[4] = {1, 0 , 0, -1}, dy[4] = {0, -1, 1, 0};
char d;

int getDir(char c){
    if(c == 'U'){
        return 1;
    }
    else if(c == 'D'){
        return 2;
    }
    else if(c == 'R'){
        return 0;
    }
    else{ // L
        return 3;
    }
}

int main() {
    // Please write your code here.
    cin >> n >> t >> y >> x >> d;
    int dir = getDir(d);
    x--;
    y--;

    // t초동안 움직이는거 해야됨. 벽부딪히고 방향 바꾼거는 횟수 쓰는거임. -> idx 벗어나면 방향 바꿈.

    // 방향 정하는 함수 정의


    // n번 만큼 이동하면서 움직이고 만약 idx 벗어나면 방향을 바꾼다.
    for(int i = 0; i < t; i++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //cout << i << "번째에 업데이트 되기 전 위치는" << nx << ", " << ny << '\n';
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            x = nx;
            y = ny;
        }
        else{
            dir = 3 - dir;
        }
        //cout << i << "번째에 업데이트 된 위치는 " << x << ", " << y << '\n';
    }

    x++;
    y++;
    cout << y  << " " << x;

    return 0;
}