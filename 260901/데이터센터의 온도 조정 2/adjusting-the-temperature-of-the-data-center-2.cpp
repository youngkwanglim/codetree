#include <iostream>
#include <algorithm>
using namespace std;
int n, c, g, h, ta[1004], tb[1004], ret;

int go(int a, int b, int t){
    if(t < a) return c;
    else if(a <= t && t <= b) return g;
    else return h;
}

int main() {
    // Please write your code here.
    cin >> n >> c >> g >> h;
    for(int i = 0; i < n; i++){
        cin >> ta[i] >> tb[i];
    }

    for(int t = -1; t <= 1001; t++){
        int tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += go(ta[i], tb[i], t);
        }
        ret = max(ret, tmp);
    }

    cout << ret;
    return 0;
}