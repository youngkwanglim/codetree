#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ret, a[24];
vector<int> v;

void CalXOR(){
    int tmp = 0;
    for(int i : v){
        tmp ^= i;
    }
    ret = max(ret, tmp);
}

void go(int cnt, int start){
    if(cnt == m){
        CalXOR();
        return;
    }

    for(int i = start; i < n; i++){
        v.push_back(a[i]);
        go(cnt + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    go(0, 0);

    cout << ret;
    return 0;
}