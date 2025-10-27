#include <iostream>

using namespace std;

int a, b, ret;

bool check3(int i){
    int tmp = 0;
    while(i > 0){
        tmp = i % 10;
        if (tmp == 3 || tmp == 6 || tmp == 9) return true;
        i /= 10;
    }
    return false;
}

bool check3Bae(int i){
    int tmp = 0;
    while(i > 0){
        tmp += i % 10;
        i /= 10;
    }
    if(tmp % 3 == 0){
        return true;
    }
    else return false;
}

int main() {
    cin >> a >> b;

    // Please write your code here.
    // 그냥 for 문 돌리면 됨
    for(int i = a; i <= b; i++){
        if(check3(i) || check3Bae(i)){
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}