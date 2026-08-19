#include <iostream>
#include <climits>
using namespace std;
int s, n, ret = INT_MAX, sum, a[104];

int main() {
    // Please write your code here.
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int tmp = a[i] + a[j];
            ret = min(ret, abs(s - sum + tmp));
        }
    } 

    cout << ret;
    return 0;
}