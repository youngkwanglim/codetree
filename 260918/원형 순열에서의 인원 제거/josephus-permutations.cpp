#include <iostream>
#include <queue>
using namespace std;
int n, k;
queue<int> q;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size()){
        for(int i = 0; i < k - 1; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}