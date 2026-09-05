#include <iostream>
using namespace std;
int n, a[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 플래그를 꺼놧다가 (== 0) 특정 높이 넘으면 cnt+하면서 flg on;
    // 플래그 켜놧을 때 특정 높이넘으면 아무일 X
    // 플래그 켜놨는데 특정 높이 밑이면 flg 끄지
    // 플래그 꺼놧다가 특정 높이 밑이면 아무일 X
    for(int h = 0; h <= 1001; h++){
        int cnt = 0;
        int flg = 0;
        for(int i = 0; i < n; i++){
            if(flg == 0 && a[i] > h){
                cnt++;
                flg = 1;
            }

            else if(flg == 1 && a[i] <= h){
                flg = 0;
            }
            ret = max(cnt, ret);
        }
    }

    cout << ret;


    return 0;
}