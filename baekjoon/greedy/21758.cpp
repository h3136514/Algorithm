// 누적합
#include <iostream>

using namespace std;
int N, num[100001], sum[100001], answer;

// 꿀 따기
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }

    // 벌1, 벌2, 벌통 위치(벌1: 맨왼쪽, 꿀통: 맨오른쪽)
    for(int i = 2; i < N; i++){
        int tmp = (sum[N] - num[1] - num[i]) + (sum[N] - sum[i]);
        answer = max(answer, tmp);
    }

    // 벌1, 벌통, 벌2 위치 (벌1: 맨왼쪽, 벌2: 맨오른쪽)
    for(int i = 2; i < N; i++){
        int tmp = (sum[i] - sum[1]) + (sum[N-1] - sum[i-1]);
        answer = max(answer, tmp);
    }

    // 벌통, 벌1, 벌2 위치(꿀통: 맨왼쪽, 벌2: 맨오른쪽)
    for(int i = 2; i < N; i++){
        int tmp = (sum[N-1] - num[i]) + sum[i-1];
        answer = max(answer, tmp);
    }

    cout << answer << "\n";

    return 0;
}