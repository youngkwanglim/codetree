#include <iostream>
#include <algorithm>
using namespace std;
int n, k, p, t;
int a[104], cnt[104];

struct Shake {
    int time, x, y;
};

Shake shake[254];

bool cmp(Shake a, Shake b){
    return a.time < b.time;
}

int main() {
    // Please write your code here.
    cin >> n >> k >> p >> t;
    a[p] = 1;

    for(int i = 0; i < t; i++){
        // 헌명이 감염되어 있으면, 그 반대편이 감염됨
        // 대신 k번까지만 감염시킴.
        cin >> shake[i].time >> shake[i].x >> shake[i].y;     
    }

    sort(shake, shake + t, cmp);
    for(int i = 0; i < t; i++){
        int x = shake[i].x, y = shake[i].y;
        if(x == 0) continue;

        bool ix = a[x], iy = a[y]; // 감염상태를 저장

        if(ix) cnt[x]++;
        if(iy) cnt[y]++;

        if(ix && cnt[x] <= k) a[y] = 1;
        if(iy && cnt[y] <= k) a[x] = 1;

        // if(a[gam[i].first] > 0 && cnt[gam[i].first] < k){
        //     cnt[gam[i].first]++;
        //     a[gam[i].second]++;
        //     a[gam[i].second]++;
        //     //cout << i << "초에 감염\n";
        //     //cout << gam[i].first << '\n';
        //     //cout << gam[i].second << '\n';
        // }
        // else if(a[gam[i].second] > 0 && cnt[gam[i].second] < k){
        //     cnt[gam[i].second]++;
        //     a[gam[i].first]++;
        //     a[gam[i].second]++;
        //     //cout << i << "초에 감염\n";
        // }
    }

    for(int i = 1; i <=n; i++){
        if(a[i]) cout << 1;
        else cout << 0;
    }

    return 0;
};
