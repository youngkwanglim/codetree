#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, n, stone[104][3], ret;

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> stone[i][0] >> stone[i][1] >> stone[i][2];
    }

    for(int i = 0; i < 3; i++){
        int ball[3] = {};
        int cnt = 0;
        ball[i] = 1;
        for(int j = 0; j < n; j++){
            int tmp = ball[stone[j][0] - 1];
            ball[stone[j][0] - 1] = ball[stone[j][1] - 1];
            ball[stone[j][1] - 1] = tmp;

            if(ball[stone[j][2] - 1] == 1) cnt++;
        }
        //cout << cnt << '\n';
        ret = max(ret, cnt);
    }

    cout << ret;
    return 0;
}