#include <iostream>
#include <vector>
using namespace std;
string num[4] ={"1", "22", "333", "4444"}, s; 
int n, ret, b_num;
vector<int> v;

void CheckBeautifulNum(){
    for(int i = 0; i < v.size(); i += v[i]){
        if(i + v[i] - 1 >= n) return;
        for(int j = i; j < i + v[i]; j++){
            if(v[j] != v[i]) return;
        }
    }
    ret++;
}

void go(int cnt){
    if(cnt == n){
        CheckBeautifulNum();
        return;
    }

    for(int i = 1; i <= 4; i++){
        v.push_back(i);
        go(cnt + 1);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;

    go(0);

    cout << ret;
    return 0;
}