#include <iostream>
#include <algorithm>
using namespace std;
int x, y, ret;

int main() {
    // Please write your code here.
    cin >> x >> y;

    for(int i = x; i <= y; i++){
        string s = to_string(i);
        string s2 = s;
        reverse(s.begin(), s.end());
        if(s == s2) ret++;
    }

    cout << ret;
    return 0;
}