// 구현, 시뮬레이션
#include <iostream>

using namespace std;
int A, B, C, s, e, sum, num[101];

// 트럭 주차
int main(){
    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        cin >> s >> e;
        for(int j = s; j < e; j++)
            num[j]++;
    }

    for(int i = 1; i <= 100; i++){
        if(num[i] == 1)
            sum += A;
        else if(num[i] == 2)
            sum += B*2;
        else if(num[i] == 3)
            sum += C*3;
    }

    cout << sum << "\n";

    return 0;
}