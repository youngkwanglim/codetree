#include <iostream>
#include <climits>
using namespace std;
int a[6], ret = INT_MAX, sum;

int main() {
    // Please write your code here.
    // 두 팀은 반복문으로 구하고, 나머지 한팀은 합계에서 빼버리면 됨. 그러면 3팀 능력이 나옴. 거기서 최소화 하는 팀 구성을 구하면 됨.
    for(int i = 0; i < 6; i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = 0; k < 6; k++){
                for(int l = k + 1; l < 6; l++){
                    if(i == k || j == k || i == l || j == l) continue; // 숫자 겹치지 않게
                    int team1 = a[i] + a[j];
                    int team2 = a[k] + a[l];
                    int team3 = sum - team1 - team2;
                    int max_team = max(team1, max(team2, team3));  
                    int min_team = min(team1, min(team2, team3));  
                    ret = min(ret, max_team - min_team);
                }
            }
        }
    }

    cout << ret;

    return 0;
}