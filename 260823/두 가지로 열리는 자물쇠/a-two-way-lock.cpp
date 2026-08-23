#include <iostream>
using namespace std;
int n, a1, a2, b1, b2, c1, c2, ret;

bool IsIn(int bar, int tmp){
    int diff = abs(bar - tmp);
    return min(diff, n - diff) <= 2;
}


// (a1 + n - 2) % n < = tmp <=  (a1 + n + 2) % n
// if (a1 - 2) < 0 이면 n 더해주고 그거보다 큰애들이고 n보다 작은애들
// // 0보다 작으면 그거 바꾸고 그거보다 크고 n보다 작거나
// if (a1 - 2) >= 0면 그냥 얘보다 크면서

// if (a1 + 2) > n이면 나머지보다 작은애들
// if (a1 + 2) <= n이면 그냥 얘보다 작은애들 

int main() {
    // Please write your code here.
    cin >> n;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if((IsIn(a1, i) && IsIn(b1, j) && IsIn(c1, k)) || (IsIn(a2, i) && IsIn(b2, j) && IsIn(c2, k))){
                    ret++;
                    //continue;
                }
                // if(IsIn(a2, i) && IsIn(b2, j) && IsIn(c2, k)){
                //     ret++;
                // }
            }
        }
    }

    cout << ret;
    return 0;

    // 1,2랑 n-1, n만 문제임. 나머지는 해당 범위에 들어옴.
    // 3부터 n-3이 a,b,c일 때는 해당 숫자부터 앞뒤로 2차이 범위안에 들어오면 됨.


    // 범위 밖 처리를 어떻게 할것인지가 문제임.
    // i, j, k 는 반복문으로 결정해두고 이것들이 범위에 해당하는지를 확인한다.
    // n을 이용해야된다.
}