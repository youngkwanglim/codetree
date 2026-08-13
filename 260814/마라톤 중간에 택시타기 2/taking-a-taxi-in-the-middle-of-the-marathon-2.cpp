#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, ret = INT_MAX, x, y;

vector<pair<int, int>> v;

int main() {
    // Please write your code here.
    cin >> n;

    // 점을 어떻게 관리를 할 것인가?
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }

    // 점 하나씩 빼면서 거리 계산해보기 abs 활용
    // 점 뺴는 것의 기준은 돌아가면서 빼기
    // n - 2번 계산을 해봐야됨

    // 붙어 있는 순서끼리만 비교를 하면 됨.

    for(int i = 1; i < n - 1; i++){

        int tmp = 0;
        for(int j = 0; j < n - 1; j++){
            if(j == i){
                continue;
            }
            else if(j + 1 == i){
                tmp += (abs(v[j].first - v[j + 2].first) + abs(v[j].second - v[j + 2].second));
                //cout << tmp << '\n';
            }
            else{
                tmp += (abs(v[j].first - v[j + 1].first) + abs(v[j].second - v[j + 1].second));
                //cout << tmp << '\n';
            }
            //cout << "hi" << '\n';
        }

        ret = min(ret, tmp);
    }

    cout << ret;

    return 0;
}