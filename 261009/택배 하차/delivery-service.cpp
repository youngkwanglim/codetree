#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a[54][54], v[104];

struct Rect{
    int si, sj, ei, ej;
};
Rect unit[104];
vector<int> ans;

void PrintA(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "==================\n";
}

int FindBottom(int si, int sj, int ei, int ej){
    for(int i = ei; i <=n; i++){
        for(int j = sj; j < ej; j++){
            if(a[i][j] != 0){
                return i;
            }
        }
    }
    return n + 1;
}

void Mark(int num, int si, int sj, int ei, int ej){
    for(int i = si; i < ei; i++) {
        for(int j = sj; j < ej; j++) {
            a[i][j] = num;
        }
    }
}

void Drop(int num){
    auto [si, sj, ei, ej] = unit[num];

    int bottom_i = FindBottom(si, sj, ei, ej);

    int n_si = bottom_i - (ei - si);
    int n_ei = bottom_i;

    // 기존 위치 지우기
    Mark(0, si, sj, ei, ej);

    // 새로운 위치에 택배 배치
    Mark(num, n_si, sj, n_ei, ej);

    // 택배 위치 갱신
    unit[num] = {n_si, sj, n_ei, ej};
}


void Gravity(int si, int sj, int ei, int ej){
    int visited[104] = {};
    for(int i = si - 1; i>= 1; i--){
        for(int j = 1; j <=n; j++){
            int num = a[i][j];

            if(num != 0 && !visited[num]){
                Drop(num);
                visited[num] = 1;
            }
        }
    }
}


int main() {
    // Please write your code here.
    cin >> n >> m;

    // 1. 택배 투입
    for (int i = 0; i < m; i++){
        int k, h, w, c;
        cin >> k >> h >> w >> c;

        int si = 1;
        int sj = c;
        int ei = 1 + h;
        int ej = c + w;

        int bottom_i = FindBottom(si, sj, ei, ej);

        int n_si = bottom_i - h;
        int n_ei = bottom_i;

        Mark(k, n_si, sj, n_ei, ej);

        unit[k] = {n_si, sj, n_ei, ej};
        v[k] = 1;
        // PrintA();
    }

    // 택배 하자
    bool left = true;

    for(int i = 0; i < m; i++){
        for(int num = 1; i <= 100; num++){
            if(v[num] == 0) continue;

            auto [si, sj, ei, ej] = unit[num];

            bool canUnload = 1;

            for(int y = si; y < ei; y++){
                if(left){
                    // 왼쪽 장애물 확인
                    for(int x = 1; x < sj; x++){
                        if(a[y][x] != 0){
                            canUnload = 0;
                            break;
                        }
                    }
                }
                else{
                    for(int x = ej; x <= n; x++){
                        if(a[y][x] != 0){
                            canUnload = 0;
                            break;
                        }
                    }
                }
                if(canUnload == 0) break;
            }

            if(canUnload){
                Mark(0, si, sj, ei, ej);

                v[num] = 0;
                ans.push_back(num);

                Gravity(si, sj, ei, ej);
                break;
            }
        }
        left = !left;
    }
    // PrintA();

    for(int num : ans){
        cout << num << '\n';
    }

    // // 2. 택배 하차 left / Drop
    // // 3. 택배 하차 right / Drop
    // for(int i = 1; i <= m; i++){
    //     int tx = -1;
    //     int tk = 200; // 얘는 작아야지 우선순위임.
    //     int flg = 0;
    //     if(i % 2 == 1){
    //         // 왼쪽부터 한번씩 돌면서 그 열에 숫자가 있는지 확인
    //         // 만약 있으면 거기서 정지. 그리고 그거 방문 처리
    //         for(int x = 1; x <= n; x++){
    //             for(int y = 1; y <= n; y++){
    //                 if(a[y][x] > 0 && a[y][x] < tk){
    //                     tx = a[y][x];
    //                     flg = 1;
    //                 }
    //             }
    //             if(flg){
    //                 clear_box[tx] = 1;
    //                 cout << tx << '\n';
    //                 break;
    //             }
    //         }
    //         Drop();
    //     }

    //     else{
    //         // 오른쪽부터 한번씩 돌면서 그 열에 숫자가 있는지 확인
    //         // 만약 있으면 거기서 정지. 그리고 그거 방문 처리
    //         for(int x = n; x >= 1; x--){
    //             for(int y = 1; y <= n; y++){
    //                 if(a[y][x] > 0 && a[y][x] < tk){
    //                     tx = a[y][x];
    //                     flg = 1;
    //                 }
    //             }
    //             if(flg){
    //                 clear_box[tx] = 1;
    //                 cout << tx << '\n';
    //                 break;
    //             }
    //         }
    //         Drop();
    //     }
    // }
    return 0;
}