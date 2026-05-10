#include <iostream>
#include <algorithm>
using namespace std;

int n, a[104];

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >>  a[i];
        if(i % 2 == 1){
            sort(a, a + i + 1);
            // 중앙값 출력
            cout << a[i/2 + 1] << " ";
        }
    }
    return 0;
}