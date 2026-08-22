#include <iostream>
using namespace std;
int n, x, ret;
char c, a[104];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        a[x] = c;
    }

    // G 또는 H로만 이루어 졌거나, G랑 H 갯수가 같아야됨.
    for(int i = 0 ; i <= 100; i++){
        if(a[i] != 'G' && a[i] != 'H') continue;
        for(int j = i; j <= 100; j++){
            int cnt_g = 0;
            int cnt_h = 0;
            //if(a[i] == '' && a[j] == '') continue;
            if(a[j] != 'G' && a[j] != 'H') continue;
            for(int k = i; k <= j; k++){
                if(a[k] == 'G') cnt_g++;
                if(a[k] == 'H') cnt_h++;
            }
            if(cnt_g > 1 && cnt_h == 0) ret = max(ret, j - i);
            if(cnt_h > 1 && cnt_g == 0) ret = max(ret, j - i);
            if(cnt_g > 0 && cnt_g == cnt_h) ret = max(ret, j - i);
        }
    }
    cout << ret;
    return 0;
}