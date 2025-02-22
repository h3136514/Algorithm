// 수학, 사칙연산
#include <iostream>

using namespace std;
long long N, sum = 1;

// 팩토리얼 2
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++)
        sum *= i;
    
    cout << sum;

    return 0;
}