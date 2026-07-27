#include <iostream>
using namespace std;
int n, x, color[200004];
char c;
int w, b;


int main() {
    // Please write your code here.
    cin >> n;
    int now = 100000;
    for(int i = 0; i < n; i++){
        cin >> x >> c;

        if(c == 'R'){
            while(x--){
                color[now] = 1;
                if(x) now++;
            }
        }
        else{
            while(x--){
                color[now] = -1;
                if(x) now--;
            }
        }
    }

    for(int i =0; i <= 200000; i++){
        if(color[i] == 1) b++;
        else if(color[i] == -1) w++;
    }

    cout << w << " " << b;
    return 0;
}