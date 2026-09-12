#include <iostream>
#include <set>
#include <climits>
using namespace std;
int n, ret;
string s;

int main() {
    // Please write your code here.
    cin >> n >> s;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= s.size() - 1 - i){

    //     }
    // }

    // 크기를 1부터 늘려감.
    // idx 0 부터 그 크기만큼 visited 계산을 함.
    // 크기는 문자열 크기의 -1 부터 시작해서 하나도 겹치는게 없으면 그게 정답이고 break하면됨.
    // 해당 문자열을 만들기 위해서는 처음부터 i 크기까지 만들어야됨. 그걸 반복해야됨.



    for(int i = s.size() - 1; i >= 1; i--){ // 크기가 5야 4
        set<string> st;
        for(int j = 0; j <= s.size() - i; j++) { // 1번만 해야됨. 2번
            string tmp;
            for(int k = 0; k < i; k++){
                tmp += s[j + k];
            }
            st.insert(tmp);
            // cout << tmp << '\n';
        }

        if(s.size() + 1 - i == st.size()) {
            ret = i;
        }
    }

    cout << ret;

    return 0;
}