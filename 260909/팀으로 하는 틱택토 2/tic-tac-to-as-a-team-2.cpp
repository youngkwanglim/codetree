#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[3][3], cnt[10][10], visited[10][10], ret;

int main() {
    // Please write your code here.
    //그냥 8줄 다 훑어보면 될 거 같은데.
    //숫자 2개로만 이루어져 있으면 ret++;
    //대신 순서 바뀐거는 동일 시 해야됨.
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 3; j++){
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < 3; i++){
        vector<int> v;
        for(int j = 0; j < 3; j++){
            v.push_back(a[i][j]);   
            // cout << a[i][j] << " ";
        }
        // cout << '\n';
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        // cout << v.size() << '\n';
        if(v.size() == 2) {
            cnt[v[0]][v[1]]++;
            cnt[v[1]][v[0]]++;
        }
    } 

    for(int i = 0; i < 3; i++){
        vector<int> v;
        for(int j = 0; j < 3; j++){
            v.push_back(a[j][i]);   
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        // cout << v.size() << '\n';
        if(v.size() == 2) {
            cnt[v[0]][v[1]]++;
            cnt[v[1]][v[0]]++;
        }
    } 

    vector<int> v = {};
    for(int i = 0; i < 3; i++){
        v.push_back(a[i][i]);   
    } 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size() == 2) {
        cnt[v[0]][v[1]]++;
        cnt[v[1]][v[0]]++;
    }

    v = {};
    for(int i = 0; i < 3; i++){
        v.push_back(a[i][2 - i]);   
    } 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size() == 2) {
        cnt[v[0]][v[1]]++;
        cnt[v[1]][v[0]]++;
    }

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(visited[i][j] == 0 && cnt[i][j]){
                ret++;
                visited[i][j]++;
                visited[j][i]++;
            }
        }
    }

    cout << ret;
    return 0;
}