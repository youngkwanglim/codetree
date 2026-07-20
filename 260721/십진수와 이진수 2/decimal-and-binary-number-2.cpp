#include <iostream>
using namespace std;
string n;
int ret, cnt, tmp, num[100];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n.size(); i++){
        tmp = 2 * tmp + (n[i] - '0'); // 10진수 변환 성공
    }

    tmp *= 17;

    while(1){
        if(tmp < 2){
            num[cnt++] = tmp;
            break;
        }

        num[cnt++] = tmp % 2;
        tmp /= 2;
    }

    for(int i = cnt - 1; i >= 0; i--){
        cout << num[i];
    }
    return 0;
}