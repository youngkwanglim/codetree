#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p;

struct Point{
    int input, start, end;
};

bool cmp(Point A, Point B){
    if(A.input == B.input) return A.start < B.start;
    return A.input < B.input;
}

int main() {
    // Please write your code here.
    cin >> n;
    Point p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].input;
        p[i].start = i + 1;
    }

    sort(p, p + n, cmp);

    // for(int i = 0; i < n; i++){
    //     p[i].end = i + 1;
    // }

    // cout << p[p[i].input;

    int ret[n + 4];
    // for(int i = 0; i < n; i++){
    //     p[i].end = i + 1;
    // }

    for(int i = 0; i < n; i++){
        ret[p[i].start] = i + 1;
    }

    for(int i = 0; i < n; i++){
        cout << ret[i + 1] << " ";
    }

    // 두번째 필드에 원래 위치를 저장한다. 그리고 정렬하고 새로운 배열에 그 값들을 넣어준다.

    return 0;
}