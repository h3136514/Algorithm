// 수학, 비트마스킹
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
long long N, CNT = 1, result;
//  500,000,000,000 < 2^39
//  3^39 < 2^62  ==> long long 으러 커버 가능


// 거듭제곱(0과 1로만 이루어진 3진수)
int main(){
    cin >> N;

    // 2진수 변환
    while(N){
        q.push(N%2);
        N /= 2;
    }

    // 계산
    while(!q.empty()){
        result = result + q.front() * CNT;
        CNT *= 3;
        q.pop();
    }

    cout << result << "\n";

    return 0;
}