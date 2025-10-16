#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;
int N, K, CNT, result = INF;
bool check = false;
vector<int> A;

// 블록 놀이
int main(){
    cin >> N >> K;
    A.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // i를 기준으로 등차수열 확인
    for(int i = 1; i <= N; i++){
        vector<int> tmp(A);
        check = false;
        CNT = 0;

        // 뒤의 값 감소
        for(int j = i-1; j >= 1; j--){
            if(tmp[j+1] - tmp[j] != K){
                CNT++;
                tmp[j] = tmp[j+1] - K; 
            }

            if(tmp[j] < 1){  // 탑의 높이는 항상 1보다 크거나 같아야 함
                check = true;
                break;
            }
        }

        if(check)
            continue;

        // 앞의 값 증가
        for(int j = i + 1; j <= N; j++){
            if(tmp[j] - tmp[j-1] != K){
                CNT++;
                tmp[j] = tmp[j-1] + K;
            }
        }

        result = min(result, CNT);
    }

    cout << result << "\n";

    return 0;
}