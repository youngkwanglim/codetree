#include <iostream>
using namespace std;
int n, m, a[1000004], b[1000004], ret, v, t, ti, loc, flg;

int main() {
    // Please write your code here.
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            ti++;
            loc += v;
            a[ti] = loc;
            //cout << ti << "초에 위치는 " << a[ti] << '\n';
        }
    }

    loc = 0;
    ti = 0;
    for(int i = 0; i < m; i++){
        cin >> v >> t;
        for(int j = 0; j < t; j++){
            ti++;
            loc += v;
            b[ti] = loc;
            //cout << ti << "초에 위치는 " << b[ti] << '\n';
        }
    }

    // 15번했으면 그 전까지 비교해야됨.

    // 선두가 바뀌는 조건을 어떻게 판단할 것인가.
    // flg 를 하나 세워서 a가 높을 때는 1 b가 높을 때는 -1, 시작은 0으로 해서 flg 바뀔 때 ret++
    for(int i = 1; i <= ti; i++){
        if(a[i] > b[i]) {
            flg = 1;    
            break;
        }
        if(b[i] > a[i]) {
            flg = -1;
            break;
        }
    }


    for(int i = 1; i <= ti; i++){
        //if(a[i] == b[i] && ((a[i - 1] > b[i - 1]) && (a[i + 1] < b[i + 1]) || (a[i - 1] < b[i - 1]) && (a[i + 1] > b[i + 1]))) ret++;
    
        if((a[i] > b[i]) && flg == -1){
            flg = 1;
            ret++;
        }
        else if ((a[i] < b[i]) && flg == 1) {
            flg = -1;
            ret++;
        }
    }

    cout << ret;

    return 0;
}