#include <iostream>
#include <vector>
using namespace std;
int n, tmp[24], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp[i];
    }

    // 3개 다 더해보면서 직접 구해봐야될것 같은데. 이건 for 3번 반복인데
    // carry 계산을 어떻게 하나..
    for(int i = 0; i < n; i++){
        //int flg = 0;
        int a[10] = {};
        int tmp_a = tmp[i];
        for(int h = 0; h < 5; h++){
            if(tmp_a) a[h] = tmp_a % 10;
            else break;
            //cout << tmp_a << ' ' << tmp_a % 10;
            tmp_a /= 10;
            //cout << '\n';
        }

        for(int j = i + 1; j < n; j++){
            int b[10] = {};
            int tmp_b = tmp[j];
            for(int h = 0; h < 5; h++){
                if(tmp_b) b[h] = tmp_b % 10;
                else break;
                tmp_b /= 10;
            }
            
            for(int k = j + 1; k < n; k++){
                int flg = 0;
                int c[10] = {};
                int tmp_c = tmp[k];
                for(int h = 0; h < 5; h++){
                    if(tmp_c) c[h] = tmp_c % 10;
                    else break;
                    tmp_c /= 10;
                }


                for(int l = 0; l < 5; l++){
                    if(a[l] + b[l] + c[l] >= 10) {
                        flg = 1;
                        break;
                    }
                    //cout << a[l] << " " << b[l] << " " << c[l] << "\n";
                }
                //cout << tmp[i] << " " << tmp[j] << " " << tmp[k] << "\n";
                if(flg == 0) ret = max(ret, tmp[i] + tmp[j] + tmp[k]);
            }
        } 
    }

    if(ret) cout << ret;
    else cout << -1;

//     각자 벡터에 넣고, reverse 때리고, 앞에서부터 숫자가 존재하면 
    

//     // 3개를 더해서 자리수별로 더해서 10 안넘너 체크를 하면 됨.
//     // 숫자를 문자열로 바꿔서 문자수 뒤부터 더해야됨.
//     for


//   800 * 10000
    return 0;
}