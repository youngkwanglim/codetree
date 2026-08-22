#include <iostream>
using namespace std;
int n, k, a[504], ai, xi, ret;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> ai >> xi;
        a[xi + 200] += ai;
    }

    // 바구니 위치는 0~100임, k는 200이면 구간은
    // 0 - 200 -> -200, 100 + 200 -> 300
    // 0 ~500으로 배치해야됨. 498 500
    for(int i = 0; i <= 500 - 2 * k; i++){
        int tmp = 0;
        for(int j = i; j <= i + 2 * k; j++){
            tmp += a[j];
        }
        ret = max(ret, tmp);
    }

    cout << ret;
    return 0;
}