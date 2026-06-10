#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Student{
    string name;
    int kor, eng, math;
};

bool compare(Student A, Student B){
    if((A.kor == B.kor) && (A.eng == B.eng)) return A.math > B.math;
    if(A.kor == B.kor) return A.eng > B.eng;
    return A.kor > B.kor;
}

int main() {
    // Please write your code here.
    cin >> n;
    Student student[n];

    for(int i = 0; i < n; i++){
        cin >> student[i].name >> student[i].kor >> student[i].eng >> student[i].math;     
    }

    sort(student, student + n, compare);

    for(int i = 0; i < n; i++){
        cout << student[i].name << " " << student[i].kor << " " << student[i].eng << " " << student[i].math << '\n';     
    }
    return 0;
}