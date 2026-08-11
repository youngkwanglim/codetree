#include <iostream>
using namespace std;
string s;
int dir = 3, dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, x, y, ret;

int main() {
    // Please write your code here.
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        else if(s[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        else{
            x += dx[dir];
            y += dy[dir];
        }
        ret++;
        if(x == 0 && y == 0){
            cout << ret;
            return 0;
        }
    }
    cout << -1;
    return 0;
}