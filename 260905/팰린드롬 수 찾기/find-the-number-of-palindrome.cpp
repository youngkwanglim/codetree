#include <iostream>
using namespace std;
int x, y, ret;

int main() {
    // Please write your code here.
    cin >> x >> y;

    for(int i = x; i <= y; i++){
        string s = to_string(i);
        int flg = 0;
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i]) {
                flg = 1;
                break;
            }
        }
        if(flg == 0) ret++;
    }

    cout << ret;
    return 0;
}