#include <iostream>
#include <vector>
using namespace std;

int n;

struct Info{
    string date, day, weather;
};

Info info[104];
vector<Info> v;

int main() {
    // Please write your code here.
    cin >> n;

    // 비오는 날 중에 가장 빠른날을 찾아야됨.
    for(int i =0; i < n; i++){
        cin >> info[i].date >> info[i].day >> info[i].weather;
        if(info[i].weather == "Rain"){
            v.push_back(info[i]); 
        }
    }

    int tmp = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i].date < v[tmp].date) tmp = i;
    }

    cout << v[tmp].date << " " << v[tmp].day << " " << v[tmp].weather;

    return 0;
}