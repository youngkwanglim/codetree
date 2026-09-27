#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> v;

void PrintNumber(){
    for(int i: v){
        cout << i << " "; 
    }
    cout << '\n';
}

void Go(int cnt){
    if(cnt == n){
        PrintNumber();
        return;
    }

    for(int i = 1; i <= k; i++){
        if(v.size() >= 2 && !(v[cnt - 1] == i && v[cnt - 2] == i)){
            v.push_back(i);
            Go(cnt + 1);
            v.pop_back();
        }
        if(v.size() < 2) {
            v.push_back(i);
            Go(cnt + 1);
            v.pop_back();
        }
    }
    // 1 2 
    // cnt = 2
    // cnt = 3
}

int main() {
    // Please write your code here.
    cin >> k >> n;
    Go(0);
    return 0;
}