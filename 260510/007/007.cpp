#include <iostream>
using namespace std;

struct Secret{
    string code, space;
    int time;
};

int main() {
    // Please write your code here.
    Secret s;
    cin >> s.code >> s.space >> s.time;
    cout << "secret code : " << s.code << '\n';
    cout << "meeting point : " << s.space << '\n';
    cout << "time : " << s.time << '\n';
    return 0;
}