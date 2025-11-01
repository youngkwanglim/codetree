#include <iostream>

using namespace std;

int n;
int arr[50];

void changeArr(int *a){
    for(int i = 0 ; i < n; i++){
        if(a[i] % 2 == 0){
            cout << a[i] / 2 << " "; 
        }
        else{
            cout << a[i] << " ";
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    changeArr(arr);

    return 0;
}