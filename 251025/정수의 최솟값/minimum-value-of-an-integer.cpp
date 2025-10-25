#include <iostream>

using namespace std;

int a, b, c;

int go(int a, int b, int c){
    return min(c,min(a,b));
}

int main() {
    cin >> a >> b >> c;

    // Please write your code here.
    cout << go(a,b,c);

    return 0;
}