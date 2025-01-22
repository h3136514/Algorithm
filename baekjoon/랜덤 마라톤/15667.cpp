// 수학, 사칙연산
#include <iostream>

using namespace std;
int N, K;

// 2018 연세대학교 프로그래밍 경진대회
int main(){
    cin >> N;
    for(int i = 1; i <= N/3; i++){
        if((1 + i + i*i) == N){
            K = i;
            break;
        }
    }

    cout << K << "\n";

    return 0;
}