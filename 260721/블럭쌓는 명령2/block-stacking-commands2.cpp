#include <iostream>
using namespace std;
int n, k, a, b, ret;

int main() {
    // Please write your code here.
    cin >> n >> k;
    int psum[n + 1] = {};
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            psum[i]++;
        }
    }

    for(int i = 1; i < n; i++){
        ret = max(ret, psum[i]);
    }

    cout << ret;

    return 0;
}