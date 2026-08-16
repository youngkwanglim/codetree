#include <iostream>
using namespace std;
string s;
int ret;

int main() {
    // Please write your code here.
    cin >> s;
    for(int i = 0; i < s.size() - 1; i++){
        for(int j = i + 2; j < s.size() - 1; j++){
            if(s[i] == '(' && s[i + 1] == '(' && s[j] == ')' && s[j + 1] == ')') ret++;
        }
    }

    cout << ret;
    return 0;
}