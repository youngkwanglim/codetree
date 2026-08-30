#include <iostream>
using namespace std;
int x, y, ret;

int DigitSum(int n){
    if(n < 10) return n;
    else return DigitSum(n / 10) + (n % 10);
}

int main() {
    // Please write your code here.
    cin >> x >> y;
    for(int i = x; i <= y; i++){
        ret = max(ret, DigitSum(i));
    }
    cout << ret;
    return 0;
}