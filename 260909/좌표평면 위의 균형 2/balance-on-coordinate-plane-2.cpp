#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int n, x[104], y[104], ret = INT_MAX;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i <= 100; i += 2){
        for(int j = 0; j <= 100; j += 2){
            int cnt_1 = 0;
            int cnt_2 = 0;
            int cnt_3 = 0;
            int cnt_4 = 0;

            for(int k = 0; k < n; k++){
                if(x[k] > i && y[k] > j) cnt_1++;
                if(x[k] < i && y[k] > j) cnt_2++;
                if(x[k] > i && y[k] < j) cnt_3++;
                if(x[k] < i && y[k] < j) cnt_4++;
            }
            ret = min(ret, max(max(cnt_1, cnt_2), max(cnt_3, cnt_4)));
        }
    } 
    cout << ret;
    return 0;
}