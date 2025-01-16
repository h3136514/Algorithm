// 구현, 사칙연산
#include <iostream>

using namespace std;
int N, num;
long long sum = 0;

// 종이접기
int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            sum += num;
        } 
    }

    cout << sum << "\n";
    
    return 0;
}