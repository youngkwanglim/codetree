#include <iostream>
using namespace std;
int m1, d1, m2, d2, ret;
string A;
string date[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int CountDay(int m, int d){
    int tmp = 0;
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < m; i++){
        tmp += days[i];
    }
    tmp += d;
    return tmp;
}

int main() {
    // Please write your code here.
    cin >> m1 >> d1 >> m2 >> d2 >> A;
    //cout << CountDay(m2, d2) << " " << CountDay(m1, d1) << " ";
    int diff = CountDay(m2, d2) - CountDay(m1, d1);

    // 7일로 나눠서 그 사이에는 무조건 A요일이 몫만큼 있음.
    ret = diff / 7;
    // cout << ret << " ";
    for(int i = 0; i <= (diff % 7); i++){
        if(date[i] == A) ret++; 
    }
    cout << ret << '\n';
    return 0;
}

// 31 + 5 = 36
// 31 + 29 + 9 = 69
// 33 / 7 = 4 * 7 + 5;