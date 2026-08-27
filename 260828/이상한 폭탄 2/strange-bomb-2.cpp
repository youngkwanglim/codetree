#include <iostream>
using namespace std;
int n, k, a[104], ret = -1;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[i] == a[j] && (j - i) <= k){
                ret = max(ret, a[i]);
            }
        }
    }
    cout << ret;
    return 0;
}