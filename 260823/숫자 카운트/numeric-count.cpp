#include <iostream>
using namespace std;
int n, b[10], one[10], two[10], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i] >> one[i] >> two[i];
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = 1; k <= 9; k++){
                int flg = 1;
                if(i == j || j == k || k == i) continue;
                // cout << i << " " << j << " " << k << '\n';
                for(int l = 0; l < n; l++){
                    int cnt_1 = 0;
                    int cnt_2 = 0;
                    int third = b[l] % 10;
                    int second = b[l] / 10 % 10;
                    int first = b[l] / 100 % 10;
                    // cout << first << " " << second << " " << third << '\n';

                    if(i == first) cnt_1++;
                    else if(i == second || i == third) cnt_2++;
                    if(j == second) cnt_1++;
                    else if(j == first || j == third) cnt_2++;
                    if(k == third) cnt_1++;
                    else if(k == first || k == second) cnt_2++;
                    // cout << cnt_1 << " " << cnt_2 << '\n';
                    
                    if(cnt_1 != one[l] || cnt_2 != two[l]) {
                        flg = 0;
                        break;
                    }
                }

                if(flg) ret++;
            }
        }
    }

    cout << ret;

    return 0;
}