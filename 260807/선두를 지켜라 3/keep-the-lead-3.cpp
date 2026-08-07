#include <iostream>
using namespace std;
int n, m, v, t, a[1000004], b[1000004], ret, now1, now2, combo;

#define MAX_COUNT 1000000

int main() {
    // Please write your code here.
    cin >> n >> m;
    //n번
    //a배열에 위치 기록
    for(int i = 0; i < n; i++){
        cin >> v >> t;
        for(int j = 1; j <= t; j++){
            now1++;
            a[now1] = a[now1 - 1] + v;
            //cout << a[now1] << ' ' << a[now1 - 1] << ' ' << v << '\n';
        }
    }

    //m번
    //b배열에 위치 기록
    for(int i = 0; i < m; i++){
        cin >> v >> t;
        for(int j = 1; j <= t; j++){
            now2++;
            b[now2] = b[now2 - 1] + v;
        }
    }

    // 조합이 바뀐걸 찾아야됨.
    // 위치는 다 기록 중
    // 그러면 매초마다 두 배열 비교해서 카운트를 해주면 될 것 같기는 한데.
    // 배열을 어떻게 판단할거냐.
    // A혼자는 1, B 혼자는2, AB는 3으로 조합값 저장
    // 이전 조합값이랑 새로운 조합값이 다르면 ret++;
    for(int i = 1; i <= now1; i++){
        int tmp = combo;
        if(a[i] > b[i]) combo = 1;
        else if(a[i] == b[i]) combo = 3;
        else combo = 2;

       //cout << "이전 콤보는 " << tmp << "현재 콤보는" << combo << '\n';

        if(tmp != combo) ret++; 
    }

    cout << ret;
    return 0;
}