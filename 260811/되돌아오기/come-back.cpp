#include <iostream>
using namespace std;
int n, d, x, y, dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, ret;
char c;

int main() {
    // Please write your code here.
    cin >> n;
    while(n--){
        cin >> c >> d;
        while(d--){
            ret++;
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
            else if(c == 'E'){
                x += dx[0];
                y += dy[0];
            }
            if(x == 0 && y == 0){
                cout << ret << '\n';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}