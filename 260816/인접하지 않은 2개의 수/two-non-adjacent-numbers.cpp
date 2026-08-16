#include <iostream>
using namespace std;
int n, a[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 2; j < n; j++){
            ret = max(ret, a[i] + a[j]);
        }
    }

    cout << ret;
    return 0;
}