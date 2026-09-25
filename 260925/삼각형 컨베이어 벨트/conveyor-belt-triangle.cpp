#include <iostream>
using namespace std;
int n, t, a[204], b[204], c[204];

int main() {
    // Please write your code here.
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    while(t--){
        int tmp1 = a[n - 1];
        int tmp2 = b[n - 1];
        int tmp3 = c[n - 1];

        for(int i = n - 1; i >= 1; i--){
            a[i] = a[i - 1] ;
            b[i] = b[i - 1] ;
            c[i] = c[i - 1] ;
        }

        a[0] = tmp3;
        b[0] = tmp1;
        c[0] = tmp2;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    return 0;
}