#include <iostream>

using namespace std;

int n, m;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    cin >> n >> m;

    // Please write your code here.
    swap(n, m);
    cout << n << " " << m;

    return 0;
}