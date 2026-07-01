#include <iostream>
#include <algorithm>
using namespace std;
const int n = 5;

struct Student{
    string name;
    int h;
    double w;
};

bool cmp(Student A, Student B){
    return A.h > B.h;
}

bool cmp2(Student A, Student B){
    return A.name < B.name;
}

int main() {
    // Please write your code here.
    Student students[n];
    cout << fixed;
    cout.precision(1);

    for(int i = 0; i < n; i++){
        cin >> students[i].name >> students[i].h >> students[i].w;
    }

    //sort(students, students + n);
    sort(students, students + n, cmp2);
    cout << "name" << '\n';
    for(int i = 0; i < n; i++){
        cout << students[i].name << " " << students[i].h << " " << students[i].w << '\n';
    }
    cout << '\n';

    sort(students, students + n, cmp);
    cout << "height" << '\n';
    for(int i = 0; i < n; i++){
        cout << students[i].name << " " << students[i].h << " " << students[i].w << '\n';
    }
    return 0;
}