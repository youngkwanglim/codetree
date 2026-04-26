#include <iostream>
using namespace std;

int go(int n){
    if(n == 1) return 2;
    if(n == 2) return 4;
    return go(n - 2) * go(n - 1) % 100;
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    cout << go(n);
    return 0;
}