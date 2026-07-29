#include <iostream>
using namespace std;
int n, k, m, a[104], ret = -1;

int main() {
    // Please write your code here.
    cin >> n >> m >> k;
    int tmp = 0;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        a[tmp]++;
        if(a[tmp] == k){
            ret = tmp;
            break;
        }  
    }

    cout << ret;
    return 0;
}