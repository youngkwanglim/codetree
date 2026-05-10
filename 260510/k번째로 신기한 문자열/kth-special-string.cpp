#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
string t;
string a[104];

int main() {
    // Please write your code here.
    cin >> n >> k >> t;

    //정렬하고 그 뒤로 t로 시작하는 index찾아서 거기서부터 k번째 출력을 하면 되지.
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);

    int tmp = 0;

    for(int i = 0; i < n; i++) {
        if(t == a[i].substr(0, t.size())) {
            tmp = i;
            break;
        }
    }

    cout << a[tmp + k - 1];

    return 0;
}