#include <iostream>
using namespace std;
int n, k, dir, ret, x, y;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, -1, 0, 1};
char a[1004][1004];

// 아래로 내려가다가 /는 왼쪽으로 \는 오른쪽으로
// 위로 올라가다가 /는 오른쪽으로 \는 왼쪽으로
// 오른쪽으로 가다가 /는 위로, \는 아래로 
// 왼쪽으로 가다가 /는 아래로, \는 위로
void SelectXY(int k){
    k--;
    int tmp = k / n;
    if(tmp == 0){
        y = 0;
        x = k % n;
    }
    else if(tmp == 1){
        y = k % n;
        x = n - 1;
    }
    else if(tmp == 2){
        y = n - 1;
        x = (n - 1) - (k % n);
    }
    else if(tmp == 3){
        y = (n - 1) - (k % n);
        x = 0;
    }
}

void SelectDir(char c){
    if(dir == 0 || dir == 2){ // 아래
        if(c == '/') dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }
    // else if(dir == 2){ // 위

    // }
    else if(dir == 1 || dir == 3){ // 왼쪽
        if(c == '/') dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
    }
    // else if(dir == 3){ // 오른쪽
}

bool IsIn(int ny, int nx){
    return (0 <= ny && ny < n && 0 <= nx && nx < n);
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cin >> k;

    // k에 따라 입장문이 달라짐. -> 시작점 및 방향 정해짐.
    // 4로 나누고 나머지를 정하면 시작점 정해지긴함. 그리고 그 4로 나눈 몫에 따라 방향 정해짐.
    dir = (k - 1) / n;
    SelectXY(k);
    while(true){
        ret++;
        //cout << y << " " << x << " " << "방향은 " << dir;
        SelectDir(a[y][x]);
        //cout << "그다음 방향은 " << dir << '\n'; 
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(!IsIn(ny, nx)){
            break;
        }
        x = nx;
        y = ny;
    }

    cout << ret;
    return 0;
}