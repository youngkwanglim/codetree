#include <iostream>
#include <algorithm>
using namespace std;
int n, t, a[1004], ret;

int main() {
    // Please write your code here.
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(i >= 1 && ((a[i] > t) && (a[i - 1] > t))) {
            tmp++;
            //cout << i << " 연달아 커짐\n";
        }
        else if(a[i] > t) {
            tmp = 1;
            //cout << i << " 처음 커짐\n";
        } 
        else tmp = 0;

        ret = max(ret, tmp);
    }


    cout << ret << '\n';
    return 0;
}