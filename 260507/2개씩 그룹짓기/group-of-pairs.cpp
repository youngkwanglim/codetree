#include <iostream>
#include <algorithm>

using namespace std;


int a[2004];
int n, ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    sort(a, a + 2 * n);

    // for(int i = 0; i < 2 * n; i++){
    //     cout << a[i];
    // }

    for(int i = 0; i < n; i++){
        ret = max(ret, a[i] + a[2 * n - i - 1]);
    }
    cout << ret << '\n';
}