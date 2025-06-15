#include <iostream>

using namespace std;
int N, K, arr[1000001], cnt, answer, st, en;

// 가장 긴 짝수 연속한 부분 수열 (large) 
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    while(st <= en){
        // 끝 구간 확장
        while(en < N){
            if(arr[en] % 2 == 1){  
                if(cnt == K)    // K번 삭제함
                    break;
                cnt++;
            }
            en++;
        }

        answer = max(answer, en - st - cnt);    // 구간 - 홀수(최대 K번 커버함)

        if(arr[st] % 2 == 1)
            cnt--;
        st++;   // 시작 구간 확장
    }

    cout << answer  << "\n";

    return 0;
}