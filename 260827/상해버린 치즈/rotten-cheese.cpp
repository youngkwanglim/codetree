#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, M, d, s, t, eat[54][104][54], p, m, sick_cheese[54], check_eat[54][54], ret;
vector<int> sc;

int main() {
    // Please write your code here.
    cin >> n >> M >> d >> s;
    // 아프다고 기록된 사람 말고도 아픈사람이 있을 수 있음
    // 아픈 시간 1초전에 치즈를 먹은사람의 치즈 번호를 같이 먹은 사람에게 약을 복용시켜야됨.

    // 치즈를 여러개 먹을 수도 있음. -> 이게 빠졋엇음.
    for(int i = 0; i < d; i++){
        cin >> p >> m >> t;
        eat[p][t][m] = 1; //사람, 시간, 먹은 치즈
    }

    for(int i = 0; i < s; i++){
        cin >> p >> t;
        for(int j = 1; j <= t - 1; j++){ // 시간
            // for(int k = 1; k <= n; k++){ // 사람
                for(int c = 1; c <= M; c++){
                    if(eat[p][j][c] && check_eat[p][c] == 0){
                        sick_cheese[c]++; // 후보를 추가해줌. 그리고 후보가 s만큼 쌓여야지 최종 후보임. 그래야 s만큼 한 치즈로 아플 수 있음.
                        check_eat[p][c]++;
                    }
                }

            // }
            //cout << j << '\n';
        }
        //sick_cheese[eat[p][t - 1]] = 1;
        // sick[p] = 1; // 아픈사람 체크
        // for(int j = 0; j < n; j++){
        //     if(eat[j][t - 1] == eat[p][t - 1]) { // 1초전에 먹은 사람들이면
        //         cheese[eat[j][t]] = 1; // 그 시간에 아팠던 치즈 저장
        //         sick[j]++;  //환자 추가
        //     }
        // }
    }

    for(int i = 1; i <= M; i++){
        if(sick_cheese[i] == s) sc.push_back(i); // 이게 최종 후보
    }

    // for(int i = 1; i <= n; i++){
    //     int flg = 0;
    //     for(int j = 1; j <= 100; j++){
    //         for(int k = 0; k <= sc.size(); k++){
    //             // if(cheese[k] == 0) continue;
    //             if(eat[i][j] == sc[k]) {
    //                 ret++;
    //                 flg = 1;
    //                 break;
    //             }
    //         }
    //         if(flg) break;
    //     }
    // }


    //cout << eat[1][1][1] << '\n';
    for(int i = 0; i < sc.size(); i++){ //치즈 후보를 정하고 시작
        int tmp = 0;
        for(int j = 1; j <= n; j++){ // 사람
            for(int k = 1; k <= 100; k++){ // 시간
                if(eat[j][k][sc[i]] == 1) {
                    tmp++;
                    //cout << "치즈후보는 " << sc[i] << " 사람은" << j << " 시간은 " << k << '\n';
                    break;
                }
            }
        }
        ret = max(tmp, ret);
    }


    cout << ret;
    return 0;
}