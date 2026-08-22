#include <iostream>
#include <climits>
using namespace std;
int n, t, h, a[104], ret = INT_MAX;

int main() {
    // Please write your code here.
    cin >> n >> h >> t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // T 구간만큼 반복했을 때 최소로 H에 대한 높이로 맞춰야됨. 원래 크기랑 H랑 차이를 구하면 됨.
    for(int i = 0 ; i < n - t + 1; i++){
        int tmp = 0;
        for(int j = i; j < i + t; j++){
            tmp += abs(a[j] - h);
        }
        ret = min(ret, tmp);
    }

    cout << ret;
    return 0;
}