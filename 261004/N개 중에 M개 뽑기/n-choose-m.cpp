#include <iostream>
#include <vector>
using namespace std;
int n, m, visited[14];
vector<int> v;

void PrintNum(){
    for(int i : v){
        cout << i << " ";
    }
    cout << '\n';
}

void go(int cnt, int start){
    if(cnt == m){
        PrintNum();
        return;
    }

    for(int i = start + 1; i <= n; i++){
        v.push_back(i);
        go(cnt + 1, i);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    go(0, 0);
    return 0;
}