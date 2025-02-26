// 구현, 시뮬레이션
#include <iostream>
#include <string>

using namespace std;
int num[4];
string str;

// 컵 위치 바꾸기
void change(int a, int b){
    int tmp;
    tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}

// Hawk eyes
int main(){
    num[0] = -1;
    num[3] = 1;

    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A')
            change(0, 1);
        else if(str[i] == 'B')
            change(0, 2);
        else if(str[i] == 'C')
            change(0, 3);
        else if(str[i] == 'D')
            change(1, 2);
        else if(str[i] == 'E')
            change(1, 3);
        else
            change(2, 3);
    }

    // 작은 공 위치
    for(int  i = 0; i < 4; i++){
        if(num[i] == -1)
            cout << i+1 << "\n";
    }
    // 큰 공 위치
    for(int  i = 0; i < 4; i++){
        if(num[i] == 1)
            cout << i+1 << "\n";
    }

    return 0;
}