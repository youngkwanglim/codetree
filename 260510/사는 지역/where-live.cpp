#include <iostream>
using namespace std;

int n;

struct Info{
    string name, addr, city;
};

Info info[14];

int main() {
    // Please write your code here.

    cin >> n;
    for(int i =0; i < n; i++){
        cin >> info[i].name >> info[i].addr >> info[i].city;
    }

    int idx = 0;
    for(int i = 0; i < n - 1; i++){
        if(info[i + 1].name > info[idx].name){
            idx = i + 1;
        }
    }

    cout << "name " << info[idx].name << '\n';
    cout << "addr " << info[idx].addr << '\n';
    cout << "city " << info[idx].city << '\n';


    return 0;
}