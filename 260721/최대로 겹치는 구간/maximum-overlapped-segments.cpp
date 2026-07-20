#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, cnt[204], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int i = a + 100; i < b + 100; i++){
            cnt[i]++;
        }
    }

    for(int i = 0; i <= 200; i++){
        ret = max(ret, cnt[i]);
    }

    cout << ret;
    return 0;
}