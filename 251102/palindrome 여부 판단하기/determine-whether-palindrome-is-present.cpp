#include <iostream>
#include <string>

using namespace std;

string A;
bool go(string s){
    string tmp = s;
    revese(s.begin(), s.end());
    if(tmp == s) return true;
    else return false;
}

int main() {
    cin >> A;

    // Please write your code here.
    if(go(A)) cout << "Yes";
    else cout << "No";

    return 0;
}