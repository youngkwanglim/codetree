#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, cnt[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            cnt[i]++;
        }
    }

    //끝점에서 닿는것도 겹치는것.
    for(int i = 1; i <= 100; i++){
        ret = max(ret, cnt[i]);
    }
    cout << ret;
    return 0;
}