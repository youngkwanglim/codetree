#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Point{
    int x, y, num;
};

bool cmp(Point A, Point B){
    if(abs(A.x)+ abs(A.y) == abs(B.x)+ abs(B.y)) return A.num < B.num;
    return abs(A.x)+ abs(A.y) < abs(B.x)+ abs(B.y);
}

int main() {
    // Please write your code here.
    cin >> n;
    Point p[n];

    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].num = i + 1;
    }

    sort(p, p + n, cmp);

    for(int i = 0; i < n; i++){
        cout << p[i].num << '\n';
    }
    return 0;
}