#include <iostream>
using namespace std;

int n = 0;

void go(int n){
    if(n == 0) return;

    cout << "HelloWorld" << '\n';

    go(n-1);
}

int main() {
    // Please write your code here.
    cin >> n;
    go(n);
    return 0;
}