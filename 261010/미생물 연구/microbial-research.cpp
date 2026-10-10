#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int n, q, a[19][19];
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
bool visited[19][19]; // 이 칸을 이미 탐색했는가?
int pieces[54];      // 이 번호의 미생물은 몇 덩어리인가?
int area[54]; // 번호별 현재 넓이
int nextA[19][19]; // 새 용기

bool compare(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<pair<int, int>> makeOrder(){
    fill(area, area + 54, 0);

    // 현재 남아 있는 넓이 계산
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int id = a[y][x];

            if (id == 0) continue;
            area[id]++;
        }
    }

    vector<pair<int, int>> order;

    for(int id = 1; id <= q; id++){
        if(area[id] == 0) continue;

        order.push_back({area[id], id});
    }

    sort(order.begin(), order.end(), compare);

    return order;
}

struct Mini{
    int si, sj, ei, ej, cnt;
};
Mini mini[54];
vector<int> ans;

void printA() {
    for (int y = n - 1; y >= 0; y--) {
        for (int x = 0; x < n; x++) {
            cout << a[y][x] << " ";
        }
        cout << '\n';
    }
    cout << "-------------------------------\n";
}




bool IsIn(int y, int x){
    return 0 <= y && y < n && 0 <= x && x < n;
}

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!IsIn(ny, nx)) continue; // 범위 밖이면 건너뜀
        if (visited[ny][nx]) continue;
        if(a[ny][nx] != a[y][x]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx);
    }
}

void countPieces(){
    fill(&visited[0][0], &visited[0][0] + 19 * 19, 0);

    for(int id = 1; id <= q; id++){
        pieces[id] = 0;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == 0) continue;
            if (visited[y][x]) continue;

            int id = a[y][x];
            visited[y][x] = 1;
            pieces[id]++; // 새로운 덩어리 하나 발견
            dfs(y, x);    // 그 덩어리 전체 방문 표시
        }
    }
}

void removeSplit() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int id = a[y][x];

            if (id == 0) continue;

            if (pieces[id] >= 2) {
                a[y][x] = 0;
            }
        }
    }
}

vector<pair<int, int>> getShape(int id){
    vector<pair<int, int>> cells;
    int minY = n;
    int minX = n;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(a[y][x] != id) continue;

            cells.push_back({y, x});

            minY = min(minY, y);
            minX = min(minX, x);
        }
    }

    for(auto& cell : cells){
        cell.first -= minY;
        cell.second -= minX;
    }

    return cells;
}

bool canPlace(int sy, int sx, vector<pair<int, int>> cells){
    for(auto cell : cells){
        int ny = sy + cell.first;
        int nx = sx + cell.second;

        if(!IsIn(ny, nx)) return false;
        if(nextA[ny][nx] != 0) return false;
    }
    return true;
}

bool placeOne(int id, vector<pair<int, int>> cells){
    for (int sx = 0; sx < n; sx++){
        for(int sy = 0; sy < n; sy++){
            if(!canPlace(sy, sx, cells)) continue;

            for(auto cell : cells) {
                int ny = sy + cell.first;
                int nx = sx + cell.second;

                nextA[ny][nx] = id;
            }

            return true;
        }
    }
    return false;
}

void moveAll(vector<pair<int, int>> order){
    fill(&nextA[0][0], &nextA[0][0] + 19 * 19, 0);

    for (auto item : order) {
        int id = item.second;
        vector<pair<int, int>> cells = getShape(id);

        placeOne(id, cells);
    }

    // 모든 배치가 끝난 뒤 현재 용기 교체
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            a[y][x] = nextA[y][x];
        }
    }
}

int getScore() {
    fill(area, area + 54, 0);
    bool adjacent[54][54] = {};

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int id = a[y][x];

            if (id == 0) continue;

            area[id]++;

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (!IsIn(ny, nx)) continue;

                int other = a[ny][nx];

                if (other == 0 || other == id) continue;

                adjacent[id][other] = true;
                adjacent[other][id] = true;
            }
        }
    }

    int result = 0;

    for (int id = 1; id <= q; id++) {
        for (int other = id + 1; other <= q; other++) {
            if (!adjacent[id][other]) continue;

            result += area[id] * area[other];
        }
    }

    return result;
}

int main() {
    // Please write your code here.
    cin >> n >> q;

    // 1. 미생물 투입
    // 일단 그냥 넣어
    for(int id = 1; id <= q; id++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; y++) {
            for(int x = x1; x < x2; x++) {
                a[y][x] = id;
            }
        }


        // 나누기 확인
        countPieces();
        removeSplit();
        // printA();

        // 2. 배양 용기 이동
        vector<pair<int, int>> order = makeOrder();
        moveAll(order);
        // cout<< "이동 후\n";
        // printA();

        // // 정렬 결과 확인
        // for (const auto& item : order) {
        //     cout << "번호: " << item.second
        //         << ", 넓이: " << item.first << '\n';
        // }

        // 3. 실험결과 기록
        cout << getScore() << '\n';
    }

    return 0;
}