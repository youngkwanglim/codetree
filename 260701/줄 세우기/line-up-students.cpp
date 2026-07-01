#include <iostream>
#include <algorithm>
using namespace std;

int N;

struct Student{
    int h, w, num;
};

bool cmp(Student A, Student B){
    if(A.h == B.h && A.w == B.w) return A.num < B.num;
    if(A.h == B.h) return A.w > B.w;
    return A.h > B.h;
}

int main() {
    // Please write your code here.
    cin >> N;
    Student s[N];

    for(int i = 0; i < N; i++){
        cin >> s[i].h >> s[i].w;
        s[i].num = i + 1; 
    }

    sort(s, s + N, cmp);

    for(int i = 0; i < N; i++){
        cout << s[i].h << " " << s[i].w << " " << s[i].num << '\n'; 
    }

    return 0;
}