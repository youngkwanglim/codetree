#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[1004];

int main() {
    // Please write your code here.
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    cout << a[k - 1];
    return 0;
}