#include <iostream>

using namespace std;

int Y, M, D;

bool checkYoon(int Y){
    if(Y % 400 == 0) return true;
    else if(Y % 100 == 0) return false;
    else if(Y % 4 == 0) return true;
    return false;
}

int main() {
    cin >> Y >> M >> D;

    // Please write your code here.
    // 월을 비교해서 체크해야될듯 월별로 달이 나눠져있음
    if(M >= 3 && M <= 5){
        if(M == 4 && D == 31) {
            cout << -1;
        }
        else{
            cout << "Spring";
        }
    }
    else if(M >= 6 && M <= 8){
        if(M == 6 && D == 31) {
            cout << -1;
        }
        else{
            cout << "Summer";
        }
    }
    else if(M >= 9 && M <= 11){
        if((M == 9 || M == 11) && D == 31) {
            cout << -1;
        }
        else{
            cout << "Fall";
        }        
    }
    else{
        if(M == 2 && checkYoon(Y) && D >= 30){
            cout << -1;
        }
        else if(M == 2 && !checkYoon(Y) && D >= 29){
            cout << -1;
        }
        else{
            cout << "Winter";
        }
    }
    return 0;
}