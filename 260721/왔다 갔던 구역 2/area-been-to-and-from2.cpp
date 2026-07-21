#include <iostream>
using namespace std;
int n, cnt[2004]; // 최대 좌우로 1000씩
int x, ret;
char c;

int main() {
    // Please write your code here.
    cin >> n;
    int tmp = 1000;
    // 중간값(=1000)에서 좌우로 왔다갔다 해야됨.
    for(int i = 0; i < n; i++){
        cin >> x >> c;
        if(c == 'R'){
            for(int i = tmp; i < tmp + x; i++){
                cnt[i]++;
                //cout << i << " ";
            }
            tmp += x;
        }
        else{
            for(int i = tmp - 1; i >= tmp - x; i--){
                cnt[i]++;
                //cout << i << " ";
            }
            tmp -= x;
        }
        //cout << "\n";
    }

    for(int i = 0; i <= 2000; i++){
        if(cnt[i] >= 2) ret++;
    }

    cout << ret;
    return 0;
}