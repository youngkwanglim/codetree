#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;

int main() {
    // Please write your code here.

    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(s1 == s2) cout << "Yes";
    else cout << "No";

    return 0;
}