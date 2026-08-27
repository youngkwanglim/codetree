#include <iostream>
using namespace std;
int n, k, match[14][24], ret;

bool CorrectCondition(int a, int b, int l){
    bool possible = false;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(match[l][i] == a && match[l][j] == b) {
                possible = true;
                break;
            }
        }
    }
    return possible;
}


int main() {
    // Please write your code here.
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> match[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){ // a랑 b는 고정 완료
            if(i == j) continue;
            int flg = 1;
            for(int l = 0; l < k; l++){
                if(!CorrectCondition(i, j, l)) {
                    //cout << i << " " << j << " " << l << '\n'; 
                    flg = 0;
                    break;
                }
            }

            if(flg) {
                ret++;
                //cout << i << " " << j << '\n';
            }
        }
    }

    //n이 1일 떄 엣지 케이스가 있을 수 있음.
    cout << ret;
    return 0;
}