#include <iostream>
#include <vector>
using namespace std;
int n, visited[10];
vector<int> v;

void PrintNum(){
    for(int i : v){
        cout << i << " ";
    }
    cout << '\n';
}

void go(int curr_num){
    if(curr_num == n){
        PrintNum();
        return;
    }

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;

        v.push_back(i);
        visited[i] = 1;
        go(curr_num + 1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    go(0);
    return 0;
}