#include <iostream>

using namespace std;

int a, b, ret;

bool check(int h){
    for(int i = 2; i < h; i++){
        if(h % i == 0){
            return false; 
        }
    }
    return true;
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    for(int i = a; i <= b; i++){
        //cout << i << " ";
        if(check(i)) {
            ret += i;
            //cout << "소수는 : " << i << '\n';
        }
    }

    cout << ret << '\n';
    return 0;
}