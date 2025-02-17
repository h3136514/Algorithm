// 수학, 정수론
#include <iostream>

using namespace std;
int N;
long long sum;

// 약수의 합 2
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        sum += (N/i)*i; // (N을 i로 나눈 몫 = 갯수) * i(해당 수)
    }

    cout << sum << "\n";

    return 0;
}