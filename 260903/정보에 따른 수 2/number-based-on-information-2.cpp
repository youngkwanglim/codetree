#include <iostream>
using namespace std;
int t, a, b, idx, ret;
char c[1004], cc;

int main() {
    // Please write your code here.
    cin >> t >> a >> b;
    for(int i = 0; i < t; i++){
        cin >> cc >> idx;
        c[idx] = cc;
    }

    for(int k = a; k <= b; k++){
        int d1 = b - a + 1;
        int d2 = b - a + 1;
        for(int i = 0; i <= b - a + 1; i++){
            if(k - i >= 1 && c[k - i] == 'S'){
                d1 = min(d1, i);
            // cout << k << " " << i << " " << d1 << '\n';

            }
            if(k + i <= 1000 && c[k + i] == 'S'){
                d1 = min(d1, i);
            // cout << k << " " << i << " " << d1 << '\n';

            }
        }

        for(int i = 0; i <= b - a + 1; i++){
            // if((k - i >= 1 && c[k - i] == 'N') || (k + i <= t && c[k + i] == 'N')){
            //     d2 = i;
            //     break;
            // }
            if(k - i >= 1 && c[k - i] == 'N'){
                d2 = min(d2, i);
            }
            if(k + i <= 1000 && c[k + i] == 'N'){
                d2 = min(d2, i);
            }
        }
        // cout << d1 << " " << d2 << '\n';
        if(d2 >= d1) ret++;
    }

    cout << ret;
    return 0;
}