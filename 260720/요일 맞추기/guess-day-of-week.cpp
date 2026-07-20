#include <iostream>
using namespace std;
int m1, d1, m2, d2, day1, day2;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string date[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main() {
    // Please write your code here.
    cin >> m1 >> d1 >> m2 >> d2;
    // d1이 몇개의 날인지 구하고
    for(int i = 1; i < m1; i++){
        day1 += day[i];
    }
    day1 += d1; //얘네가 무조건 월요일임.

    // d2가 몇개의 날인지 구하고
    for(int i = 1; i < m2; i++){
        day2 += day[i];
    }
    day2 += d2;

    int tmp = 0;
    tmp = ((day2 - day1) % 7 + 7) % 7;
    //else tmp = (day2 - day1) % 7; // 여기는 무조건 맞음.


    cout << date[tmp] << '\n';

    return 0;
}