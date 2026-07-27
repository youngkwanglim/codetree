#include <iostream>
using namespace std;
int n, color[204][204], x1, x2, y1, y2, r, b;

int main() {
    // Please write your code here.
    cin >> n;
    for(int cnt = 1; cnt <= n; cnt++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i  = x1 + 100; i < x2 + 100; i++){
            for(int j = y1 + 100; j < y2 + 100; j++){
                if(cnt % 2){ // 빨강
                    color[i][j] = 1;
                    //cout << i << " red " << j << '\n';
                }
                else{ // 파랑
                    color[i][j] = 2;
                    //cout << i << " blue " << j << '\n';
                } 
            }
        }
    }

    for(int i  = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            //if(color[i][j] == 1) r++;
            if(color[i][j] == 2) b++;
        }
    }

    cout << b;
    return 0;
}