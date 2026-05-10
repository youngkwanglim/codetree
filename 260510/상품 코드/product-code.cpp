#include <iostream>
#include <utility>

using namespace std;

struct Product{
    string name;
    string code;
};

int main() {
    // Please write your code here.
    Product p1, p2;
    p1.name = "codetree";
    p1.code = "50";

    cin >> p2.name >> p2.code;

    cout << "product " << p1.code << " is " << p1.name << '\n';
    cout << "product " << p2.code << " is " << p2.name << '\n';
}