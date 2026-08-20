#include <iostream>
using namespace std;
int n, k, a[20004], ret, num;
char pat;

int main() {
    // Please write your code here.
    cin >> n >> k;

    // 위치에 따른 점수를 배열에 넣어두기
    for(int i = 0; i < n; i++){
        cin >> num >> pat;
        if(pat == 'G') a[num] = 1;
        else a[num] = 2;
    }

    for(int i = 0; i < 10; i++){
        //cout << a[i] << " ";
    }

    // 완탐으로 탐색하여 최대 점수 구하기
    for(int i = 1; i <= 10000; i++){
        int tmp = 0;
        for(int j = i; j <= i + k; j++){
            // cout << i << " " << j << '\n';
            tmp += a[j];
        }
        //cout << tmp << '\n';
        ret = max(ret, tmp);
    }

    cout << ret;
    return 0;
}