#include <iostream>

using namespace std;

int n;
int arr[100];

int go(int n){
    if(n == 0) return arr[0]; 
    return(max(go(n - 1), arr[n]));
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