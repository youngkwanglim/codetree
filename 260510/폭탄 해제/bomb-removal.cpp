#include <iostream>
using namespace std;

struct Bomb{
    string code;
    char color;
    int second;
};

int main() {
    // Please write your code here.
    Bomb b;
    cin >> b.code >> b.color >> b.second;
    cout << "code : " << b.code << '\n' << "color : " << b.color << '\n' << "second : " << b.second;
    return 0;
}