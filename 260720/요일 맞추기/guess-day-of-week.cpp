#include <iostream>
using namespace std;
int m1, d1, m2, d2, day1, day2;

string date[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int NumOfDays(int m, int d){
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;

    for(int i = 1; i < m; i++){
        total_days += day[i];
    }
    total_days += d;
    return total_days;
}

int main() {
    // Please write your code here.
    cin >> m1 >> d1 >> m2 >> d2;
    // // d1이 몇개의 날인지 구하고
    // for(int i = 1; i < m1; i++){
    //     day1 += day[i];
    // }
    // day1 += d1; //얘네가 무조건 월요일임.

    // // d2가 몇개의 날인지 구하고
    // for(int i = 1; i < m2; i++){
    //     day2 += day[i];
    // }
    // day2 += d2;

    int diff = NumOfDays(m2, d2) - NumOfDays(m1, d1);
    while(diff < 0) diff += 7;

    cout << date[diff % 7] << '\n';

    return 0;
}