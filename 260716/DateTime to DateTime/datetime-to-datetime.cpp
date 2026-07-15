#include <iostream>
using namespace std;
int a, b, c, ret;

int main() {
    // Please write your code here.
    cin >> a >> b >> c;
    ret = (a - 11) * 24 * 60 + (b - 11) * 60 + (c - 11);
    if(ret >= 0) cout << ret;
    else cout << -1;
    return 0;
}