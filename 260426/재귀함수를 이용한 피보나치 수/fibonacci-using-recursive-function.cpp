#include <iostream>
using namespace std;

int go(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    return go(n - 1) + go(n - 2);
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    cout << go(n);
    return 0;
}