#include <iostream>
#include <climits>
using namespace std;
int ret = INT_MAX, a[5], sum;

int main() {
    // Please write your code here.
    for(int i = 0; i < 5; i++){
        cin >> a[i];
        sum += a[i];
    }

    // 2명 팀, 2명 팀, 나머지 팀 이렇게 만들면 3팀 만들어짐.
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(i == k || j == k) continue;
                int team1 = a[i] + a[j];
                int team2 = a[k];
                int team3 = sum - team1 - team2;
                if(team1 == team2 || team2 == team3 || team3 == team1) continue;

                int diff = abs(team1 - team2);
                diff = max(diff, abs(team2 - team3));
                diff = max(diff, abs(team3 - team1));
                ret = min(ret, diff);
            }
        }
    }

    if(ret == INT_MAX) cout << -1;
    else cout << ret;

    return 0;
}