#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int t, a, b, idx, ret, s[1004], n[1004], cnt_s, cnt_n;
char c[1004], cc;

int main() {
    // Please write your code here.
    cin >> t >> a >> b;
    for(int i = 0; i < t; i++){
        cin >> cc >> idx;
        if(cc == 'S') s[cnt_s++] = idx;
        else n[cnt_n++] = idx;
    }

    for(int k = a; k <= b; k++){
        int d1 = INT_MAX;
        int d2 = INT_MAX;
        for(int i = 0; i < cnt_s; i++){
            d1 = min(d1, abs(s[i] - k));
        }
        for(int i = 0; i < cnt_n; i++){
            d2 = min(d2, abs(n[i] - k));
        }
        // cout << d1 << " " << d2 << '\n';
        if(d2 >= d1) ret++;
    }

    cout << ret;
    return 0;
}