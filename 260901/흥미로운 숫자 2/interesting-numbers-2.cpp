#include <iostream>
using namespace std;
int ret, x, y;

int main() {
    // Please write your code here.
    cin >> x >> y;
    for(int i = x; i <= y; i++){
        int n = i;
        int cnt[10] = {};
        while(n){
            cnt[n % 10]++;
            n /= 10;
        }
        
        int flg_a = 0;
        int flg_b = 0;
        for(int j = 0; j <= 9; j++){
            if(cnt[j] == 1){
                flg_a++;
            }
            if(cnt[j] > 1){
                flg_b++;
            }
        }
        if(flg_a == 1 && flg_b == 1) ret++;
    }

    cout << ret;
    return 0;
}