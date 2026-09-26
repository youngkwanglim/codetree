#include <iostream>
#include <vector>
using namespace std;
int k, n;
vector<int> v;

void PrintNum(){
    for(int i: v){
        cout << i << " ";
    }
    cout << '\n';
}

void go(int num){
    if(num == n + 1) {
        PrintNum();
        return;
    }

    for(int i = 1; i <= k; i++){
        v.push_back(i);
        go(num + 1);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> k >> n;
    go(1);
    return 0;
}