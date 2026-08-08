#include <iostream>
using namespace std;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
int x, y, cnt, n;
char c;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> cnt;
        for(int i = 0; i < cnt; i++){
            if(c == 'W'){
                x += dx[2];
                y += dy[2];
            }
            else if(c == 'S'){
                x += dx[1];
                y += dy[1];
            }
            else if(c == 'N'){
                x += dx[3];
                y += dy[3];
            }
            else{ // c == 'E' 
                x += dx[0];
                y += dy[0];
            }
        }
    }

    cout << x << " " << y;
    return 0;
}