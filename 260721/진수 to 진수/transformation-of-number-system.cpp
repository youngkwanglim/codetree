#include <iostream>
using namespace std;
int a, b, num[100], cnt;
string s;

int main() {
    // Please write your code here.
    cin >> a >> b >> s;
    int tmp = 0;
    for(int i = 0; i < s.size(); i++){
        tmp = a * tmp + (s[i] - '0');
    }

    while(true){
        if(tmp < b){
            num[cnt++] = tmp;
            break;
        }

        num[cnt++] = tmp % b;
        tmp /= b;
    }

    for(int i = cnt - 1; i >= 0; i--){
        cout << num[i];
    }

    return 0;
}