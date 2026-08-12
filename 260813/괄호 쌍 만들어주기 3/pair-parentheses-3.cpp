#include <iostream>
#include <climits>
using namespace std;
string s;

int main() {
    // Please write your code here.
    cin >> s;
    
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j < s.size(); j++){
            if((i < j) && s[i] == '(' && s[j] == ')') ret++;
        }
    }

    cout << ret;
    return 0;
}