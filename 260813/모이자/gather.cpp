#include <iostream>
#include <climits>
using namespace std;
int n, a[104];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 반복문 돌면서 집 위치를 정하고 그 위치 차이만큼 사람 곱해서 계산을 해서 최소값들 게속 없데이트하기.
    int ret = INT_MAX;
    for(int i = 0; i < n; i++){
        //int home = a[i];
        int tmp = 0;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            tmp += abs((i - j) * a[j]);
        }
        ret = min(ret, tmp);
    }

    cout << ret;
    return 0;
}