#include <iostream>
using namespace std;
int n, k, p, t, a[104], cnt[104];
pair<int, int> gam[255];

int main() {
    cin >> n >> k >> p >> t;
    a[p] = 1;

    for (int i = 0; i < t; i++) {
        int T, x, y;
        cin >> T >> x >> y;
        gam[T] = {x, y};   // 시간을 인덱스로 → 정렬 불필요
    }

    for (int i = 1; i <= 250; i++) {
        int x = gam[i].first, y = gam[i].second;
        if (x == 0) continue;          // 그 시간에 악수 없음

        bool ix = a[x], iy = a[y];     // 이 악수 '전'의 감염 상태를 먼저 저장

        if (ix) cnt[x]++;              // 감염자는 무조건 악수 횟수 소모
        if (iy) cnt[y]++;

        if (ix && cnt[x] <= k) a[y] = 1;
        if (iy && cnt[y] <= k) a[x] = 1;
    }

    for (int i = 1; i <= n; i++) cout << (a[i] ? 1 : 0);
    return 0;
}