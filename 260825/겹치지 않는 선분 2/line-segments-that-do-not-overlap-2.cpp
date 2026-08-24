#include <iostream>
using namespace std;
int n, x1[104], x2[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x1[i] >> x2[i];
    }

    // 완탐으로 진행을 해야될 것 같음
    // 교차하려면 x 큰 부분이 서로 달라야됨.
    for(int i = 0; i < n; i++){
        int flg = 1;
        for(int j = 0; j < n; j++){
            // if((x1[i] <= x2[i] && x2[j] >= x1[j] && x2[j] < x2[i] && x1[i] < x1[j]) ||
            //    (x1[i] >= x2[i] && x2[j] <= x1[j] && x2[j] > x2[i] && x1[i] > x1[j])){
            //     flg = 0;
            //     break;
            // }
            // if((x1[i] <= x2[j] && x2[i] >= x1[j]) ||
            //    (x1[i] >= x2[j] && x2[i] <= x1[j])){
            //     flg = 0;
            //     break;
            // }]
            if(i == j) continue;
            if((x1[i] < x1[j] && x2[i] > x2[j]) ||
               (x1[i] > x1[j] && x2[i] < x2[j])){
                flg = 0;
                break;
            }
        }
        
        if(flg) ret++;
    }
    cout << ret;

    return 0;
} 