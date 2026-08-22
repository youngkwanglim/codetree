#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[104], b[104], ret, tmp[104];

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b, b + m);

    for(int i = 0; i <= n - m; i++){
        int flg = 0;
        for(int j = 0; j < m; j++){
            tmp[j] = a[i + j];
        }
        sort(tmp, tmp + m);


        for(int k = 0; k < m; k++){
            if(b[k] != tmp[k]){
                flg = 1;
                break;
            }
        }

        if(flg == 0) ret++;
    }

    cout << ret;

    return 0;
}