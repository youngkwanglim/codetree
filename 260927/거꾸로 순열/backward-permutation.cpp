#include <iostream>
#include <vector>
using namespace std;
int n, visited[10];
vector<int> v;

void go(int curr_num){
    if(curr_num == n){
        for(int i : v){
            cout << i << " ";
        }
        cout << '\n';
        return;
    } 

    for(int i = n; i >= 1; i--){
        if(visited[i]) continue;
        visited[i] = 1;
        v.push_back(i);
        go(curr_num + 1);
        visited[i] = 0;
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    go(0);
    return 0;
}