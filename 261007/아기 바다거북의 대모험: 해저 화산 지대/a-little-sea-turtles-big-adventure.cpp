#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Turtle{
    int y, x, cnt;
    bool fossil;
};

struct Volcano{
    int y, x;
    int p;
    int magma;
    bool fired;
};

int n, m, k;
int a[24][24];

Turtle turtles[14];
Volcano volcanoes[24 * 24];

// 우 하 좌 상
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}


// i번 거북이를 기준으로 목적지에서 BFS
vector<vector<int>> EndBFS(int idx){
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // 현재 살아있는 다른 거북이 위치 표시
    bool hasTurtle[24][24] = {};

    for(int i = 0; i < m; i++){

        // 자기 자신은 장애물이 아님
        if(i == idx) continue;

        // 화석은 a[][]에 이미 저장되어 있음
        if(turtles[i].fossil) continue;

        // 탈출한 거북이
        if(turtles[i].y == n - 1 &&
           turtles[i].x == n - 1)
            continue;

        hasTurtle[turtles[i].y][turtles[i].x] = true;
    }


    // 목적지에서 BFS 시작
    q.push({n - 1, n - 1});
    dist[n - 1][n - 1] = 0;


    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(!IsIn(ny, nx)) continue;
            if(dist[ny][nx] != -1) continue;

            // 바다가 아니면 이동 불가
            // 산호와 화석이 여기서 걸러짐
            if(a[ny][nx] != 0) continue;

            // 다른 살아있는 거북이
            if(hasTurtle[ny][nx]) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return dist;
}


// 1단계
void go(){

    // 번호가 작은 거북이부터 이동
    for(int i = 0; i < m; i++){

        // 이미 화석화
        if(turtles[i].fossil)
            continue;

        // 이미 탈출
        if(turtles[i].y == n - 1 &&
           turtles[i].x == n - 1)
            continue;


        int y = turtles[i].y;
        int x = turtles[i].x;

        // 현재 턴까지 살아 있음
        turtles[i].cnt++;


        // 앞 거북이가 움직였을 수도 있으므로
        // 매 거북이마다 다시 BFS
        auto dist = EndBFS(i);


        // 목적지까지 갈 방법이 없음
        if(dist[y][x] == -1)
            continue;


        // 우 하 좌 상
        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(!IsIn(ny, nx)) continue;

            // 최단 거리가 1 감소하는 곳
            // dist가 존재한다는 것 자체가
            // 산호/화석/다른 거북이가 없다는 뜻
            if(dist[ny][nx] != dist[y][x] - 1)
                continue;


            turtles[i].y = ny;
            turtles[i].x = nx;

            // 목적지에 도착하더라도
            // a[][]를 건드릴 필요 없음
            // 살아있는 거북이를 a에 넣지 않기 때문

            break;
        }
    }
}


// 2단계
void plusMagma(){

    for(int i = 0; i < k; i++){
        volcanoes[i].magma += 10;
    }
}


// 화산 하나가 터졌을 때 열기 전파
void spreadHeat(int idx, int heat[24][24]){

    int y = volcanoes[idx].y;
    int x = volcanoes[idx].x;
    int p = volcanoes[idx].p;


    // 화산 자신의 위치
    heat[y][x] += p;


    // 4방향
    for(int d = 0; d < 4; d++){

        int ny = y + dy[d];
        int nx = x + dx[d];

        int power = p / 2;


        while(IsIn(ny, nx) && power > 0){

            // 산호를 만나면 해당 방향 전파 종료
            if(a[ny][nx] == 1)
                break;

            heat[ny][nx] += power;

            power /= 2;

            ny += dy[d];
            nx += dx[d];
        }
    }
}


// 3단계
void fire(){

    // 이번 턴에만 존재하는 열기
    int heat[24][24] = {};


    while(true){

        bool newFire = false;


        for(int i = 0; i < k; i++){

            // 이번 턴에 이미 분출
            if(volcanoes[i].fired)
                continue;


            int y = volcanoes[i].y;
            int x = volcanoes[i].x;


            // 기존 압력 + 이번 턴 받은 열기
            if(volcanoes[i].magma + heat[y][x]
                >= volcanoes[i].p){

                volcanoes[i].fired = true;
                newFire = true;

                spreadHeat(i, heat);
            }
        }


        // 새로 분출한 화산이 없다면
        // 연쇄 반응 끝
        if(!newFire)
            break;
    }


    // 모든 연쇄반응이 끝난 뒤
    // 거북이 화석화 확인
    for(int i = 0; i < m; i++){

        if(turtles[i].fossil)
            continue;

        // 탈출한 거북이
        if(turtles[i].y == n - 1 &&
           turtles[i].x == n - 1)
            continue;


        int y = turtles[i].y;
        int x = turtles[i].x;


        if(heat[y][x] >= 20){

            turtles[i].fossil = true;

            // 이 칸은 이후 거북이가 지나갈 수 없는 화석
            a[y][x] = 2;
        }
    }
}


// 4단계
void reset(){

    for(int i = 0; i < k; i++){

        // 이번 턴 터진 화산만
        // 기존 압력 초기화
        if(volcanoes[i].fired){
            volcanoes[i].magma = 0;
        }

        // 다음 턴을 위해 초기화
        volcanoes[i].fired = false;
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m >> k;


    // 0 = 바다
    // 1 = 산호
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }


    // 거북이
    for(int i = 0; i < m; i++){

        int y, x;
        cin >> y >> x;

        turtles[i].y = y;
        turtles[i].x = x;

        // 전역 배열이므로
        // cnt = 0
        // fossil = false

        // a[y][x]에 거북이를 저장하지 않음
    }


    // 화산
    for(int i = 0; i < k; i++){

        int y, x, p;
        cin >> y >> x >> p;

        volcanoes[i].y = y;
        volcanoes[i].x = x;
        volcanoes[i].p = p;

        // magma = 0
        // fired = false
    }


    for(int turn = 1; turn <= 100; turn++){

        // 1. 거북이 이동
        go();

        // 2. 화산 압력 증가
        plusMagma();

        // 3. 화산 분출 및 연쇄 반응
        fire();

        // 4. 환경 초기화
        reset();
    }


    for(int i = 0; i < m; i++){

        // 화석
        if(turtles[i].fossil){
            cout << -1 << '\n';
        }

        // 탈출 성공
        else if(turtles[i].y == n - 1 &&
                turtles[i].x == n - 1){

            cout << turtles[i].cnt << '\n';
        }

        // 100턴 내 탈출 실패
        else{
            cout << -1 << '\n';
        }
    }


    return 0;
}