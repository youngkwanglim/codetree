#include <iostream>
using namespace std;

struct Person{
    char codeName;
    int score;
};

Person person[5];

int main() {
    // Please write your code here.
    for(int i = 0; i < 5; i++){
        cin >> person[i].codeName >> person[i].score;
    }

    //돌면서 최저값 index 구하고, 마지막에 그거 출력해주기    

    int tmp = 0;
    for(int i = 1; i < 5; i++){
        if(person[i].score < person[tmp].score){
            tmp = i;
        }
    }

    cout <<  person[tmp].codeName << " " << person[tmp].score;
    return 0;
}