#include <iostream>
using namespace std;
int n, y[104], x[104], ret;

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> y[i] >> x[i];
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int x1 = x[i];
                int x2 = x[j];
                int x3 = x[k];
                int y1 = y[i];
                int y2 = y[j];
                int y3 = y[k];
                int tmp = 0;
                if((y[i] == y[j]) && ((x[i] == x[k]) || (x[j] == x[k]))){
                    tmp = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)); 
                }

                if((y[j] == y[k]) && ((x[j] == x[i]) || (x[k] == x[i]))){
                    tmp = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)); 
                }

                if((y[i] == y[k]) && ((x[i] == x[j]) || (x[k] == x[j]))){
                    tmp = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)); 
                }
                ret = max(ret, tmp);

            }
        }
    }

    cout << ret;

    return 0;
}