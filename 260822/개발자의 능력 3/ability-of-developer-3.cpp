#include <iostream>
#include <climits>
using namespace std;
int a[6], sum, ret = INT_MAX;

int main() {
    // Please write your code here.
    for(int i = 0; i < 6; i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                int sum1 = a[i] + a[j] + a[k];
                int sum2 = sum - sum1;
                ret = min(ret, abs(sum1 - sum2));
            }
        }
    }

    cout << ret;
    return 0;
}