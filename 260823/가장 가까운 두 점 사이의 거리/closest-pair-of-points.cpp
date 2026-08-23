#include <iostream>
#include <climits>
using namespace std;
int x[104], y[104], n, ret = INT_MAX;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int diff_x = abs(x[i] - x[j]);
            int diff_y = abs(y[i] - y[j]);
            ret = min(ret, diff_x * diff_x + diff_y * diff_y);
        }
    }

    cout << ret;
    return 0;
}