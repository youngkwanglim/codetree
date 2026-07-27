#include <iostream>
using namespace std;
int n, x1, y1, x2, y2, s[204][204], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 + 100; j < x2+ 100; j++){
            for(int k = y1 + 100; k < y2 + 100; k++){
                s[j][k]++;
            }
        }
        //cout << ret << '\n';
    }

    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            if(s[i][j]) ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}