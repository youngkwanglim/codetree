#include <iostream>
using namespace std;
int x, y, ret;

int main() {
    // Please write your code here.
    cin >> x >> y;
    for(int i = x; i <= y; i++){
        int tmp = 0;
        int now = i;
        while(now > 0){
            tmp += now % 10;
            now /= 10;
        }
        ret = max(ret, tmp);
    }
    cout << ret;
    return 0;
}