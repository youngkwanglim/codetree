#include <iostream>
using namespace std;
int num[100], n, b, cnt, ret;

int main() {
    // Please write your code here.
    cin >> n >> b;
    while(1){
        if(n < b){
            num[cnt++] = n;
            break;
        }

        num[cnt++] = n % b;
        n /= b;
    }

    for(int i = cnt - 1; i >= 0; i--){
        cout << num[i];
    }
    return 0;
}