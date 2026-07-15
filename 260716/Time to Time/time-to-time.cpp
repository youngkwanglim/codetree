#include <iostream>
using namespace std;
int a, b, c, d;
int h, m;

int main() {
    // Please write your code here.
    cin >> a >> b >> c >> d;
    h = (c - a) * 60 + d - b; 
    cout << h;
    return 0;
}