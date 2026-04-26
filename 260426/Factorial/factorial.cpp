#include <iostream>

using namespace std;

int N;

int go(int n){
    if(n == 1) return 1;
    return go(n - 1) * n;
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << go(N);
    return 0;
}