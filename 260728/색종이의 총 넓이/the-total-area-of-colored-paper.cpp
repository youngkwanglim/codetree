#include <iostream>
using namespace std;
int n, x, y, cnt[204][204], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x += 100;
        y += 100;
        for(int i = x; i < x + 8; i++){
            for(int j = y; j < y + 8; j++){
                cnt[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            if(cnt[i][j]) ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}