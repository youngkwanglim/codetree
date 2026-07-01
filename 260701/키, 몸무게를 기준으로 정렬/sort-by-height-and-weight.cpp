#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Student{
    string name;
    int h, w;
};

bool cmp(Student A, Student B){
    if(A.h == B.h) return A.w > B.w;
    return A.h < B.h;
}

int main() {
    // Please write your code here.
    cin >> n;
    Student students[n];
    for(int i = 0; i < n; i++){
        cin >> students[i].name >> students[i].h >> students[i].w;
    }

    sort(students, students + n, cmp);
    for(int i = 0; i < n; i++){
        cout << students[i].name << " " << students[i].h << " " << students[i].w << '\n';
    }

    return 0;
}