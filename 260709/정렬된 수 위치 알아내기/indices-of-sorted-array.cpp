#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    // Please write your code here.
     // 두번째 필드에 원래 위치를 저장한다. 그리고 정렬하고 새로운 배열에 그 값들을 넣어준다.
    cin >> n;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i + 1;
    }

    sort(p.begin(), p.end());


    int ret[n + 4];

    for(int i = 0; i < n; i++){
        ret[p[i].second] = i + 1;
    }

    for(int i = 0; i < n; i++){
        cout << ret[i + 1] << " ";
    }
    return 0;
}