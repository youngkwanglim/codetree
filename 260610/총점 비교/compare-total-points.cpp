#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Student{
    string name;
    int a, b, c;
};

bool compare(const Student A, Student B){
    return A.a + A.b + A.c < B.a + B.b + B.c;
}

int main() {
    // Please write your code here.
    cin >> n;

    Student student[n];
    
    for(int i = 0; i < n; i++){
        cin >> student[i].name >> student[i].a >> student[i].b >> student[i].c;
    }

    sort(student, student + n, compare);

    for(int i = 0; i < n; i++){
        cout << student[i].name << " " << student[i].a << " " << student[i].b << " " << student[i].c << '\n';
    }

    return 0;
}