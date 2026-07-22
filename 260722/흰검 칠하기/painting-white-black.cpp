#include <iostream>
using namespace std;
int n, black[200004], white[200004], color[200004], x, x1[200004], x2[200004];
char LR[200004];
char c;
int b, w, g;

int main() {
    // Please write your code here.
    cin >> n;
    int now = 0;
    char past_c = ' ';
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        LR[i] = c;
        //if(past_c == c) x--;

        if(c == 'R'){
            x1[i] = now;
            x2[i] = now + (x - 1);
            now += (x - 1);
            //color[now + 100] = 1; 
        }
        else{
            x1[i] = now - (x - 1);
            x2[i] = now;
            now -= (x - 1);
            //color[now + 100] = -1; 
        }
        x1[i] += 100000;
        x2[i] += 100000;
        //past_c = c; 
    }

    for(int i = 0; i < n; i++){
        for(int j = x1[i]; j <= x2[i]; j++){
            // cout << j << ' ';
            // cout << LR[i] << ' ';
            //cnt[j]++;
            if(LR[i] == 'R') {
                black[j]++;
                color[j] = 1;
                //cout << j << "에서 검정 칠함\n";
            }
            else {
                white[j]++; 
                color[j] = -1;
                //cout << j << "에서 흰색 칠함\n";
            }
        }
        //cout << '\n';
    }

    for(int i = 0; i <= 200000; i++){
        if(black[i] >= 2 && white[i] >= 2) {
            g++;
            // cout << i << "에서 회색 감지\n";
        }
        else if(color[i] == 1) b++;
        else if(color[i] == -1) w++;
        // else if(color[i] == 1) {
        //     b++;
        //     cout << i << "에서 검정 감지\n";
        // }

        // else if(color[i] == -1) {
        //     w++;
        //     cout << i << "에서 흰색 감지\n";
        // }
    }

    //현재 타일 포함을 놓쳤음. 이거 정신차리고 계산해야됨. 그리고 각각 2번이여서 따로 카운트해야될 듯 ㅅ2ㅂ
    // 검정인지 흰색인지 판단필요
    //같은 방향일 때가 문제임.
    cout << w << " " << b << " " << g;
    return 0;
}