#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, M, d, s, t, eat[54][104][54], p, m, sick_cheese[54], check_eat[54][54], ret;
vector<int> sc;

struct Info1{
    int p, m, t;
};
struct Info2{
    int p, t;
};
Info1 info1[1004];
Info2 info2[54];

int main() {
    // Please write your code here.
    cin >> n >> m >> d >> s;

    // 치즈를 여러개 먹을 수도 있음. -> 이게 빠졋엇음.
    for(int i = 0; i < d; i++){
        cin >> info1[i].p >> info1[i].m >> info1[i].t;
    }

    for(int i = 0; i < s; i++){
        cin >> info2[i].p >> info2[i].t;
    }

    for(int i = 1; i <= m; i++){
        int time[54] = {};
        for(int j = 0; j < d; j++){
            if(info1[j].m != i){
                continue;
            }

            int person = info1[j].p;
            if(time[person] == 0 || time[person] > info1[j].t){
                time[person] = info1[j].t;
            }
        }

        int possible = 1;
        for(int j = 0; j < s; j++){
            int person = info2[j].p;
            if(time[person] == 0 || time[person] >= info2[j].t){
                possible = 0;
            }
        }

        int pill = 0;
        if(possible){
            for(int j = 1; j <= n; j++){
                if(time[j]) pill++;
            }
        }

        ret = max(ret, pill);
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
    // for(int i = 0; i < sc.size(); i++){ //치즈 후보를 정하고 시작
    //     int tmp = 0;
    //     for(int j = 1; j <= n; j++){ // 사람
    //         for(int k = 1; k <= 100; k++){ // 시간
    //             if(eat[j][k][sc[i]] == 1) {
    //                 tmp++;
    //                 //cout << "치즈후보는 " << sc[i] << " 사람은" << j << " 시간은 " << k << '\n';
    //                 break;
    //             }
    //         }
    //     }
    //     ret = max(tmp, ret);
    // }


    cout << ret;
    return 0;
}