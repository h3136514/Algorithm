// 누적합, 이분탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N, M, A[1000], B[1000];
long long answer;
vector<int> sumA, sumB;

// 두 배열의 합(부 배열의 쌍을 구한다.)
int main(){
    cin >> T;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    for(int i = 0; i < N; i++){
        int sum = A[i];
        sumA.push_back(sum);
        for(int j = i+1; j < N; j++){
            sum += A[j];
            sumA.push_back(sum);
        }
    }
    for(int i = 0; i < M; i++){
        int sum = B[i];
        sumB.push_back(sum);
        for(int j = i+1; j < M; j++){
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());
    for(int i = 0; i < sumA.size(); i++){
        int target = T - sumA[i];

        int sIdx = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin(); // lower_bound: target값 보다 크거나 같은 첫 번째 원소의 주소를 리턴
        int eIdx = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin(); // upper_bound: 처음으로 target값을 초과하는 원소의 주소를 리턴
    
        int cnt = (eIdx - sIdx); // 타겟과 같은 수들 개수
        answer += cnt;
    }

    cout << answer << "\n";

    return 0;
}