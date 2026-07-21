#include <iostream>
using namespace std;

#define MAX_N = 104

int n, cnt[2004]; // 최대 좌우로 1000씩
int x1[104], x2[104];
int x, ret;
char c;

int main() {
    // Please write your code here.
    cin >> n;
    int tmp = 0;
    // 중간값(=1000)에서 좌우로 왔다갔다 해야됨.
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        if(c == 'R'){
            x1[i] = tmp;
            x2[i] = tmp + x;
            tmp += x;
        }
        else{
            x1[i] = tmp - x;
            x2[i] = tmp;
            tmp -= x;
        }
        //cout << "\n";

        x1[i] += 1000;
        x2[i] += 1000;
    }

    for(int i = 0; i < n; i++){
        for(int j = x1[i]; j < x2[i]; j++){
            cnt[j]++;
        }
    }

    for(int i = 0; i <= 2000; i++){
        if(cnt[i] >= 2) ret++;
    }

    cout << ret;
    return 0;
}