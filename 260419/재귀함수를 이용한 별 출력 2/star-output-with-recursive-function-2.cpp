#include <iostream>
using namespace std;

int n;

void go(int n){
    if(n == 0) return;
    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << '\n';
    go(n - 1);
    for(int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << '\n';
}

int main() {
    // Please write your code here.
    cin >> n;
    go(n);
    return 0;
}