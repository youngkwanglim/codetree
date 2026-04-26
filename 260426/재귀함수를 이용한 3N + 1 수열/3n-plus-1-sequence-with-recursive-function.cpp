#include <iostream>

using namespace std;

int n;

int go(int n){
    if(n == 1) return 0;

    if(n % 2 == 0) return go(n / 2) + 1;
    else return go(n * 3 + 1) + 1;
}

int main() {
    cin >> n;

    // Please write your code here.
    cout << go(n);
    return 0;
}