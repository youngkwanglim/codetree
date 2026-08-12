#include <iostream>
using namespace std;
int n, a[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j =  i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(a[i] <= a[j] && a[j] <= a[k]) ret++;
            }
        }
    }

    cout << ret;
    return 0;
}