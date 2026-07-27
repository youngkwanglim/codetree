#include <iostream>
using namespace std;
int x1, x2, y1, y2, r[2004][2004], a, b, c, d, e, f, g, h, cnt;

int main() {
    // Please write your code here.
    // cin >> x1 >> y1 >> x2 >> y2;

    // cin >> a >> b >> c >> d >> e >> f >> g >> h;
    
    // x1 = min(a, e);
    // x2 = max(c, g);

    // y1 = min(b, f);
    // y2 = max(d, h);


    // for(int i = x1 + 1000; i < x2 + 1000; i++){
    //     for(int j = y1 + 1000; j < y2 + 1000; j++){
    //         r[i][j] = 1;
    //     }
    // }

    cin >> a >> b >> c >> d;
    for(int i = a + 1000; i < c + 1000; i++){
        for(int j = b + 1000; j < d + 1000; j++){
            r[i][j] = 1;
        }
    }


    cin >> a >> b >> c >> d;
    for(int i = a + 1000; i < c + 1000; i++){
        for(int j = b + 1000; j < d + 1000; j++){
            r[i][j] = 2;
        }
    }

    cin >> a >> b >> c >> d;
    for(int i = a + 1000; i < c + 1000; i++){
        for(int j = b + 1000; j < d + 1000; j++){
            r[i][j] = 0;
        }
    }

    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            if(r[i][j]) cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}