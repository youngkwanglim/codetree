#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[104], b[104];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}