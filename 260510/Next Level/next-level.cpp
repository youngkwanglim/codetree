#include <iostream>
using namespace std;

struct Character{
    string id = "codetree";
    int level = 10;
};

int main() {
    // Please write your code here.
    Character cha1, cha2;
    cin >> cha2.id >> cha2.level;

    cout << "user " << cha1.id << " lv " << cha1.level << '\n'; 
    cout << "user " << cha2.id << " lv " << cha2.level << '\n'; 

    return 0;
}