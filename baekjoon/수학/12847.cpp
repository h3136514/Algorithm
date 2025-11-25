// 누적 합
#include <iostream>

using namespace std;
int N, M, num[100001];
long long sum, maxSum;

// 꿀 아르바이트
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    for(int i = 0; i < M; i++){
        sum += num[i];
    }
    maxSum = sum;
    for(int i = M; i < N; i++){
        sum -= num[i-M];
        sum += num[i];

        maxSum = max(maxSum, sum);
    }

    cout << maxSum << "\n";

    return 0;
}