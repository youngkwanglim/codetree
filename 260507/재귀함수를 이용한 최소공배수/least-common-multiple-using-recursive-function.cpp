#include <iostream>

using namespace std;

int n;
int arr[10];

int gcd(int a, int b){
    if(a > b){
        int tmp = 0;
        tmp = a;
        a = b;
        b = tmp;
    }
    if(a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int go(int index){
    if(index == 0) return arr[0];

    return lcm(go(index - 1), arr[index]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    cout << go(n - 1);
    return 0;
}