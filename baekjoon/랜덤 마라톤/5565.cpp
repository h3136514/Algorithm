// 구현, 수학
#include <iostream>

using namespace std;
int sum, num;

// 영수증
int main(){
    cin >> sum;
    for(int i = 0; i < 9; i++){
        cin >> num;
        sum -= num;
    }

    cout << sum << "\n";

    return 0;
}