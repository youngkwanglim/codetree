#include <iostream>

using namespace std;

int N;

int go(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    return go(n - 2) + n;
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << go(N);
    return 0;
}