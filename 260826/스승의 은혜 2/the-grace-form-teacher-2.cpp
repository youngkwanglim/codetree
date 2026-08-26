#include <iostream>
#include <algorithm>
using namespace std;
int n, b, p[1004], ret;

int main() {
    cin >> n >> b;
    // 정렬을 일단 하고 체크함. 근데 마지막에 걸리면 1/2로 계산해보고 체크를 함.

    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    sort(p, p + n);

    for(int i = 0; i < n; i++){
        //cout << b - p[i] << " ";
        if(b - p[i] >= 0){
            b -= p[i];
            ret++;
            //cout << p[i] << " ";
        }
        else if(b - p[i] / 2 >= 0){
            ret++;
            break;
        }
    }

    cout << ret;
    return 0;
}