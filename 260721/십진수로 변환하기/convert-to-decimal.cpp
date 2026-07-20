#include <iostream>
using namespace std;
string s;
int n;

int main() {
    // Please write your code here.
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') n = 2 * n + 1;
        else n *= 2;
    }

    cout << n;

    // do{
    //     for(int i = 0; i < s.size(); i++){
    //         if(s[i] == '1') 
    //     }
    // } while(true)
    return 0;
} 