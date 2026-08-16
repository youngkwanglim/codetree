#include <iostream>
#include <vector>
using namespace std;
int n, a[24], ret = -1;

// 12345
int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 3개 다 더해보면서 직접 구해봐야될것 같은데. 이건 for 3번 반복인데
    // carry 계산을 어떻게 하나..
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int flg = 0;

                if(a[i] % 10 + a[j] % 10 + a[k] % 10 >= 10){
                    flg = 1;
                }

                if(a[i] % 100 / 10 + a[j] % 100 / 10 + a[k] % 100 / 10 >= 10){
                    flg = 1;
                }

                if(a[i] % 1000 / 100 + a[j] % 1000 / 100 + a[k] % 1000 / 100 >= 10){
                    flg = 1;
                }

                if(a[i] % 10000 / 1000 + a[j] % 10000 / 1000 + a[k] % 10000 / 1000 >= 10){
                    flg = 1;
                }

                if(flg == 0) ret = max(ret, a[i] + a[j] + a[k]);
            }
        } 
    }

    cout << ret;
    return 0;
}