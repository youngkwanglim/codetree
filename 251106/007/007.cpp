#include <iostream>
#include <string>

using namespace std;

string secret_code;
char meeting_point;
int t;

struct Seceret{
    string s;
    char c;
    int i;
};

int main() {
    cin >> secret_code >> meeting_point >> t;

    // Please write your code here.
    Seceret secret = {secret_code, meeting_point, t};
    cout << "secret code : " << secret.s << '\n';
    cout << "meeting point : " << secret.c << '\n';
    cout << "time : " << secret.i << '\n';

    return 0;
}