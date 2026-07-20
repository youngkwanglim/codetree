#include <iostream>
using namespace std;
int n, a[100], cnt;

int main() {
    // Please write your code here.
    cin >> n;
    while(true){
        if(n < 2){
            a[cnt++] = n;
            break;
        }

        a[cnt++] = n % 2;
        n /= 2;
    }

    for(int i = cnt - 1; i >= 0; i--){
        cout << a[i];
    }
    return 0;
}