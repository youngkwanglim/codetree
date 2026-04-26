#include <iostream>
using namespace std;

int go(int n){
    if(n == 1) return 0;
    if(n % 2 == 0) return go(n / 2) + 1;
    else return go(n / 3) + 1;
}

int main() {
    int nn;
    // Please write your code here.
    cin >> nn;
    cout << go(nn);
    return 0;
}