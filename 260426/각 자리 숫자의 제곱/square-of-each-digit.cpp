#include <iostream>
using namespace std;

int n;

int go(int n){
    if(n < 10) return n * n;
    return (n % 10) * (n % 10) + go(n / 10); 
}

int main() {
    // Please write your code here.
    cin >> n;
    cout << go(n);
    return 0;
}