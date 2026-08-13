#include <iostream>
using namespace std;
string s, s2;
int ret, tmp, gop;


int main() {
    // Please write your code here.
    cin >> s;
    // 문자열 길이가 최대 10이니까 한자리씩 바꿔가면서 최대값을 구하면 됨
    for(int i = 0; i < s.size(); i++){
        string s2 = s;
        if(s[i] == '0'){
            s2[i] = '1';
        }
        else{
            s2[i] = '0';
        }

        tmp = 0;
        for(int j = 0; j < s.size(); j++){
            tmp = tmp * 2 + (s2[j] - '0');
        }
        ret = max(ret, tmp);
    }

    cout << ret;

    return 0;
}