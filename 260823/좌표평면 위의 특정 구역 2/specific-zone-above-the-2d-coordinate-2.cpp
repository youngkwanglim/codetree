#include <iostream>
#include <climits>
using namespace std;
int n, x[104], y[104], ret = INT_MAX;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){ // i는 제외하는 점임.
        int min_x = 40000;
        int max_x = 0;
        int min_y = 40000;
        int max_y = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            min_x = min(min_x, x[j]);
            max_x = max(max_x, x[j]);
            min_y = min(min_y, y[j]);
            max_y = max(max_y, y[j]);
        }
        ret = min(ret, (max_x - min_x) * (max_y - min_y));
    }   

    cout << ret;
    return 0;
}