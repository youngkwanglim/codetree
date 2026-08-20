#include <iostream>
using namespace std;
int n, k, ret, a[104] ;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - k + 1; i++){
        int tmp = 0;
        for(int j = i; j < i + k; j++){
            tmp += a[j];
        }
        ret = max(tmp, ret);
    }

    cout << ret;
    return 0;
}