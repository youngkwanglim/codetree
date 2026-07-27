#include <iostream>
using namespace std;
int n, a[1004], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }

    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(i != 0 && a[i] == a[i - 1]) tmp++;
        else tmp = 1;
        ret = max(ret, tmp);
    }

    cout << ret;

    return 0;
}