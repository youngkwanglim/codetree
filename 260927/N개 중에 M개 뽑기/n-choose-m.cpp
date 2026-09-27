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

    for(int i = start; i <= n; i++){
        if(!visited[i]){
            // visited[i] = 1;
            v.push_back(i);
            go(cnt + 1, i + 1);
            // visited[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    go(0, 1);
    return 0;
}