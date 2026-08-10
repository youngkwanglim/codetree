#include <iostream>
using namespace std;
string s;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, dir = 3, y, x;

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
        else{ // 'F' 한칸 앞으로 이동
            x += dx[dir], y += dy[dir];
        }
        //cout << dir << " ";
    }

    cout << x << " " << y;
    return 0;
}