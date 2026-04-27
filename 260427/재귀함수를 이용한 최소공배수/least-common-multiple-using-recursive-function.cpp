#include <iostream>

using namespace std;

int n;
int arr[10];
// 최대 공약수를 구하고, 그거에 곱하면 최대 공배수긴 함.
// 그걸 여러번 반복하면됨.


int gcd(int a, int b){
    int min = 0;
    if(a > b) min = b;
    else min = a;

    int tmp = 1;
    for(int i = 1; i <= min; i++){
        if(a % i == 0 && b % i == 0){
            tmp = i;
        }
    }

    return a * b / tmp;
}

int go(int k){
    if(k == 1) return arr[1];
    return gcd(go(k - 1), arr[k]);
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