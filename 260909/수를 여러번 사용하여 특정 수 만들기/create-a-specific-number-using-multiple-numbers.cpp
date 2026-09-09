#include <iostream>
using namespace std;
int a, b, c, ret;

int main() {
    // Please write your code here.
    cin >> a >> b >> c;
    for(int i = 0; i <= c; i++){
        for(int j = 0; j <= c; j++){
            int tmp = a * i + b * j;
            if(tmp <= c) ret = max(ret, tmp);
        }
    }

    cout << ret;
    return 0;
}