#include <iostream>
using namespace std;
int n, m, a[1000004], b[1000004], k, cnt = 1, now;
char c;

int main() {
    // Please write your code here.
    cin >> n >> m;
    now = 0;
    cnt = 1;
    for(int i = 0; i < n; i++){
        cin >> c >> k;
        //cnt++;
        if(c == 'R'){
            while(k--){
                a[cnt] = ++now;
                // cout << cnt << "에 " << now << '\n';
                //now++;
                cnt++;
            }
        }
        else{
            while(k--){
                a[cnt] = --now;
                // cout << cnt << "에 " << now << '\n';
                //now--;
                cnt++;
            }
        }
    }

    now = 0;
    cnt = 1;
    for(int i = 0; i < m; i++){
        cin >> c >> k;
        //cnt++;
        if(c == 'R'){
            while(k--){
                b[cnt] = ++now;
                // cout << cnt << "에 " << now << '\n';
                //now++;
                cnt++;
            }
        }
        else{
            while(k--){
                b[cnt] = --now;
                // cout << cnt << "에 " << now << '\n';
                //now--;
                cnt++;
            }
        }
    }

    int ret = -1;
    for(int i = 1; i <= cnt - 1; i++){
        if(a[i] == b[i]) {
            //cout << a[i] << " " << b[i] << '\n';
            ret = i;
            break;
        }
    }

    cout << ret;
    return 0;
}