#include <iostream>
using namespace std;
int n, x[24], y[24], ret;

int check(){
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            for(int k = 0; k <= 10; k++){
                
                //n개만큼 cnt가 쌓이면 이제 그만 확인해도 됨.
                int cnt_1 = 0;
                // 가로 3
                for(int l = 0; l < n; l++){
                    if(x[l] == i || x[l] == j || x[l] == k) cnt_1++;
                }

                int cnt_2 = 0;
                // 가로 2
                for(int l = 0; l < n; l++){
                    if(x[l] == i || x[l] == j || y[l] == k) cnt_2++;
                }

                int cnt_3 = 0;
                // 가로 1
                for(int l = 0; l < n; l++){               
                    if(x[l] == i || y[l] == j || y[l] == k) cnt_3++;
                }

                int cnt_4 = 0;
                // 가로 0
                for(int l = 0; l < n; l++){   
                    if(y[l] == i || y[l] == j || y[l] == k) cnt_4++;
                }

                if(cnt_1 == n || cnt_2 == n || cnt_3 == n || cnt_4 == n) return 1;
            }
        }
    }
    return 0;
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    // 직선 3개를 정해서 그 직선 3개가 나머지 점을 다 만족시키는지 확인해야됨.

    // 가로 3개 세로 0개
    // 가로 2개 세로 1개
    // 가로 1개 세로 2개
    // 가로 0개 세로 3개
    ret = check();
    cout << ret;
    return 0;
}