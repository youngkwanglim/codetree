#include <iostream>

using namespace std;

int n;
int arr[10];
// 최대 공약수를 구하고, 그거에 곱하면 최대 공배수긴 함.
// 그걸 여러번 반복하면됨.

// 유클리드 호제법 (재귀)
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int go(int k){
    if(k == 0) return arr[0];
    return lcm(go(k - 1), arr[k]);
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