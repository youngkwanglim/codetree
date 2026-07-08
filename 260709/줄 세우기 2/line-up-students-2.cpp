#include <iostream>
#include <algorithm>

using namespace std;

int N;
int h[1000];
int w[1000];

struct Student{
    int h, w, idx;
};

bool compare(Student A, Student B){
    if(A.h == B.h) return A.w > B.w;
    return A.h < B.h;
}

int main() {
    cin >> N;
    Student sd[N];
    for (int i = 0; i < N; i++) {
        cin >> sd[i].h >> sd[i].w;
        sd[i].idx = i + 1;
    }

    sort(sd, sd + N, compare);

    for(int i = 0; i < N; i++){
        cout << sd[i].h << " " << sd[i].w << " " << sd[i].idx << '\n';
    }

    return 0;
}