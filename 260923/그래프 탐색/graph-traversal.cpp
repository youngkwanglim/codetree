#include <iostream>
using namespace std;
int n, m, a[1004][1004], visited[1004], x, y, ret;

void go(int now){
    if(visited[now]) return;
    visited[now] = 1;
    ret++;
    for(int i = 1; i <= n; i++){
        if(a[now][i] && !visited[i]){
            go(i);
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    
    // for(int i = 1; i <= n; i++){
    //     if(!visited[i]){
    //         ret++;
    //         go(i);
    //     }
    // }
    go(1);

    // for(int i = 1; i <= n; i++){
    //     if(visited[i]) ret++;
    // }

    cout << ret - 1;
    return 0;
}