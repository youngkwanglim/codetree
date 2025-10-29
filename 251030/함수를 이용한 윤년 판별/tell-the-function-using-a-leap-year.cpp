#include <iostream>

using namespace std;

int y;

bool checkYoon(int Y){
    if(Y % 400 == 0) return true;
    else if(Y % 100 == 0) return false;
    else if(Y % 4 == 0) return true;
    return false;
}

int main() {
    cin >> y;

    // Please write your code here.
    if(checkYoon(y)) cout << "true" <<'\n';
    else cout << "false" << '\n';

    return 0;
}