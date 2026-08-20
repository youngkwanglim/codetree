#include <iostream>
using namespace std;
int n, a[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 2중 반복문으로 idx를 정함
    // 그 안에서  sum 구하고 나눠서 평균 구함. 나머지가 0인 경우만 cnt해줘야됨.
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int sum = 0;
            int tmp = 0;
            for(int k = i; k <= j; k++){
                sum += a[k];
            }

            if(sum % (j - i + 1) == 0) {
                tmp = sum / (j - i + 1);
               // cout << i << " " << j << " " << tmp << '\n' ;
            }
            else continue;

            for(int k = i; k <= j; k++){
                if(a[k] == tmp){
                    // cout << tmp << '\n';
                    ret++;
                    break;
                }
            }
        }
        
    }

    cout << ret;
    return 0;
}