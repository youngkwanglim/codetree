#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int ret = INT_MAX, n, a[104];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        a[i] *= 2;
        for(int j = 0; j < n; j++){
            vector<int> v;
            for(int k = 0; k < n; k++){
                if(j != k) v.push_back(a[k]);
            }

            int tmp = 0;
            for(int k = 0; k <= n - 3; k++){
                tmp += abs(v[k] - v[k + 1]);
            }
            // 5개에서 하나 빼면 0~3 그중 2

            ret = min(tmp, ret);
        }
        a[i] /= 2;
    }

    // 2배 idx 고르고
    // 제거 idx 고르고
    // 그러면 나머지를 tmp 배열에 넣어주고.

    cout << ret;
    return 0;
}