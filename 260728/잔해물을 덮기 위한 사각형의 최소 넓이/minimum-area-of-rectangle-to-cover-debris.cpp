#include <iostream>
using namespace std;
int x1, x2, y1, y2, color[2004][2004], ret;
int min_x = 2000, max_x = 0, min_y = 2000, max_y = 0;

int main() {
    // Please write your code here.
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + 1000; i < x2 + 1000; i++){
        for(int j = y1 + 1000; j < y2 + 1000; j++){
            color[i][j] = 1;
        }
    }

    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 + 1000; i < x2 + 1000; i++){
        for(int j = y1 + 1000; j < y2 + 1000; j++){
            color[i][j] = 0;
        }
    }


    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            if(color[i][j]){
                min_x = min(min_x, i);
                max_x = max(max_x, i);
                min_y = min(min_y, j);
                max_y = max(max_y, j);
            }
        }
    }

    //cout << min_x << ' ' << max_x << ' ' << min_y << ' ' << max_y;

    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}