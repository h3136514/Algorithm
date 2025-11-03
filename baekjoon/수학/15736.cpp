#include <iostream>

using namespace std;
int N, answer = 1;

// 청기 백기 (약수가 홀수개인 수 => 완전제곱수)
int main(){
    cin >> N;
    while(answer*answer <= N)
        answer++;

    cout << answer-1 << "\n";
    return 0;
}