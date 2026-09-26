#include <iostream>
using namespace std;
string num[4] ={"1", "22", "333", "4444"}, s; 
int n, ret, b_num;

void go(){
    if(b_num > n) return;
    if(b_num == n) ret++;
    for(int i = 1; i <= 4; i++){
        b_num += i;
        go();
        b_num -= i;
    }
}

int main() {
    // Please write your code here.
    cin >> n;

    go();

    cout << ret;
    return 0;
}