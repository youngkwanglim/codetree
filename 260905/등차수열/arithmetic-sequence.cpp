#include <iostream>
#include <algorithm>
using namespace std;
int n, a[104], l, r, tmp, ret, cnt_k[104];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            l = a[i];
            r = a[j];
            if(l > r){
                tmp = 0;
                tmp = l;
                l = r;
                r = tmp;
            }

            int cnt = 0;
            for(int k = l + 1; k <= r - 1; k++){
                if(r - k == k - l) cnt_k[k]++;
            }
        }
    }

    for(int i = 1; i <= 100; i++){
        ret = max(ret, cnt_k[i]);
    }

    cout << ret;
    return 0;
}