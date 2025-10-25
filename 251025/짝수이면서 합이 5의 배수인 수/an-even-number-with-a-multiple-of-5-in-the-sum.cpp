#include <iostream>

using namespace std;

int n;

bool pan(int i){
    return ((i % 10) + i/10) % 5 == 0 && n % 2 == 0;
}

int main() {
    cin >> n;

    // Please write your code here.
    if(pan(n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}