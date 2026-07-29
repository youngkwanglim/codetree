#include <iostream>
using namespace std;
int n, ret, a[1004], k;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(i != 0; a[i - 1] < a[i]) tmp++;
        else tmp = 1;
        ret = max(ret, tmp);
    }

    cout << ret << '\n';

    return 0;
}