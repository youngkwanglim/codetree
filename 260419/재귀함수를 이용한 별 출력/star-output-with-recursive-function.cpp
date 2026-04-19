#include <iostream>
using namespace std;

void go(int n){
    if(n == 0) return;
    go(n - 1);
    for(int i = 0; i < n; i++){
        cout << "*";
    }
    cout << "\n";
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    go(n);
    return 0;
}