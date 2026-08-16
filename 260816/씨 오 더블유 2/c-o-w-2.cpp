#include <iostream>
using namespace std;
int n, cc, co, cw, ret;
string a;

int main() {
    // Please write your code here.
    cin >> n;
    cin >> a;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(a[i] == 'C' && a[j] == 'O' && a[k] == 'W'){
                    ret++;
                }
            }
        }
    }

    cout << ret;



    // for(int i = 0; i < n; i++){
    //     cin >> c;
    //     if(c == 'C'){
    //         cc++;
    //     }
    //     else if(c =='O'){
    //         co++;
    //     }
    //     else{
    //         cw++;
    //     }
    // // }

    // cout << cc * co * cw;
    return 0;
}