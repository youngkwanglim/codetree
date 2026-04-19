#include <iostream>

using namespace std;

int N;

void go(int n){
    if(n == 0) return;
    cout << n << " ";
    go(n - 1);
    cout << n << " ";
}

int main() {
    cin >> N;
    go(N);
    return 0;
}