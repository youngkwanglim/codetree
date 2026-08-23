#include <iostream>
using namespace std;
int n, a[104], b[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    // 미리 사람마다 운영시작, 운행종료 시작을 저장해둠.
    // 사람 1명씩 제거해보면서 운행 시작, 운행 끝시간을 통해 가동시간을 구해봄.
    for(int i = 0; i < n; i++){ // 제거 할 사람을 구함.
        int work[1004] = {};
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = a[j]; k < b[j]; k++){
                work[k]++;
            }
        }
        for(int k = 1; k <= 1000; k++){
            if(work[k]) cnt++;
        }
        ret = max(ret, cnt);
    }

    cout << ret;
    return 0;
}