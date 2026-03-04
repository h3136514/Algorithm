#include <iostream>

using namespace std;
int num, sum = 300;

// 체육은 수학과목 입니다 2
int main(){
    for(int i = 0; i < 4; i++){
        cin >> num;
        sum += num;
    }

    if(1800 >= sum)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}