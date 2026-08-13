#include <iostream>
#include <climits>

using namespace std;
int n, a[1005], ret = INT_MAX; // 최솟값 구하는 문제

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 남을 방 지정
    // 갈 방 순회

    //무조건 왼쪽으로 돌아야됨.
    for(int i = 0; i < n; i++){ // 방정함
        int tmp = 0;
        for(int j = 0; j < n; j++){
            //if(i == j) continue;
            tmp += (j - i + n) % n * a[j];
            //cout << i << "번째 방에서 " << j << "번째 방까지의 거리는 " << (j - i + n) % n * a[j]  <<  '\n' ;
        }
        //cout << tmp << '\n';

        ret = min(ret, tmp);
    }

    cout << ret;
    return 0;
}