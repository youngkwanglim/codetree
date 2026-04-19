#include <iostream>
using namespace std;

void go1(int n){
    if(n == 0) return;
    go1(n - 1);
    cout << n << " ";
}

void go2(int n){
    if(n == 0) return;
    cout << n << " ";
    go2(n - 1);
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    go1(n);
    cout << "\n";
    go2(n);
    return 0;
}