#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n;

int main() {
    // Please write your code here.
    cin >> n;
    tuple<int, string, int> person[n];

    for(int i = 0; i < n; i++){
        string name;
        int h, w;
        cin >> name >> h >> w;
        person[i] = make_tuple(h, name, w);
    }

    sort(person, person + n);

    for(int i = 0; i < n; i++){
        string name;
        int h, w;
        tie(h, name, w) = person[i];
        cout << name << " " << h << " " << w << '\n';
    }    

    return 0;
}