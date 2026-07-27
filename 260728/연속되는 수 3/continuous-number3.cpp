#include <iostream>
#include <algorithm>
using namespace std;
int n, a[2004], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(i != 0 && ((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0 && a[i - 1] < 0))) tmp++;
        else tmp = 1;
        ret = max(ret, tmp);
    }    

    cout << ret;
    return 0;
}