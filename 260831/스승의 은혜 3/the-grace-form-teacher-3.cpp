#include <iostream>
#include <algorithm>
using namespace std;
struct Gift{
    int p, s, sum;
};
Gift gift[1004];
int n, b, ret;

bool cmp(Gift a, Gift b){
    if(a.sum == b.sum) return a.p < b.p;
    return a.sum < b.sum;
}

int main() {
    // Please write your code here.
    cin >> n >> b;
    for(int i = 0; i < n; i++){
        cin >> gift[i].p >> gift[i].s;
        gift[i].sum = gift[i].p + gift[i].s;
    }
    sort(gift, gift + n, cmp);

    for(int i = 0; i < n; i++){
        // cout << b << '\n';
        // cout << gift[i].p << " " << gift[i].s << " " << gift[i].sum << '\n';
        if(b - gift[i].sum >= 0){
            b -= gift[i].sum;
            ret++;
        }
        else if(b - (gift[i].p / 2 + gift[i].s) >= 0){
            b -= (gift[i].p / 2 + gift[i].s);
            ret++;
            break;
        }
        // cout << b << '\n';
        // cout << '\n';
    }

    cout << ret;
    return 0;
}