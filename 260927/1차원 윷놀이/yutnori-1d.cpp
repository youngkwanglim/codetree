#include <iostream>
#include <vector>
using namespace std;
int n, m, k, a[16], ret, horse[10];
vector<int> v;

// void CalResult(){
//     int horse[5] = {};
//     int tmp = 0;
//     for(int i = 0; i < n; i++){
//         horse[v[i]] += a[i];
//     }

//     for(int i = 1; i <= k; i++){
//         if(horse[i] >= m - 1) tmp++;
//     }
//     ret = max(ret, tmp);
// }

int Calc() {
    int score = 0;
    for(int i = 0; i < k; i++){
        if(horse[i] >= m - 1) score++;
    }
    return score;
}

void Go(int num){
    ret = max(ret, Calc());

    if(num == n){
        return;
    }

    for(int i = 0; i < k; i++){
        horse[i] += a[num];
        Go(num + 1);
        horse[i] -= a[num];
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    Go(0);

    // 어떤 말을 갈지 정하고(순열) 그만큼 이동하고 다시 돌아오고 마지막에서 번호 넘었으면 그게 결과인거고.
    cout << ret;
    return 0;
}