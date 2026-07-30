#include <iostream>
using namespace std;
int n, m, a[2000004], b[2000004], t, time_a, time_b, ret;
char d;

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> t >> d;
        while(t--){
            time_a++;
            if(d == 'L'){
                a[time_a] = a[time_a - 1] - 1;
                // cout << time_a << "번째에 좌로 이동해서 지금 " << a[time_a] << '\n';
            }
            else{
                a[time_a] = a[time_a - 1] + 1;
                // cout << time_a << "번째에 우로 이동해서 지금 " << a[time_a] << '\n';
            }
        }

    }

    //cout << '\n';
    for(int i = 0; i < m; i++){
        
        cin >> t >> d;
        while(t--){
            time_b++;
            if(d == 'L'){
                b[time_b] = b[time_b - 1] - 1;
                // cout << time_b << "번째에 좌로 이동해서 지금 " << b[time_b] << '\n';
            }
            else{
                b[time_b] = b[time_b - 1] + 1;
                // cout << time_b << "번째에 우로 이동해서 지금 " << b[time_b] << '\n';
            }
        }

    }

    //총 거리 합이 2000000을 안넘는다. 즉 1씩 최대로 움직여도 2000000안넘는다.
    if(time_a > time_b){
        for(int i = time_b + 1; i <= time_a; i++){
            b[i] = b[time_b];
        }
    }
    if(time_a < time_b){
        for(int i = time_a + 1; i <= time_b; i++){
            a[i] = a[time_a];
        }
    }


    // 바로 직전 같은 위치이면 안됨.
    // 채워주고 만약 위치 같으면 직전 위치 check 하면 될듯? i!=1 조건도 필수.
    for(int i = 1; i <= max(time_a, time_b); i++){
        if(i >= 1 && a[i] == b[i]){
            if(a[i - 1] != b[i - 1]) {
                ret++;
               // cout << i << "번째\n";
            }
        }
    }

    cout << ret <<'\n';
    return 0;
}