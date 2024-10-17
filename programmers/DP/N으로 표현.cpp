#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
vector<unordered_set<int>> dp(9);   // N 사용횟수기준 가능한 수 저장

// NN(idx==1), NNN(idx==2), NNNN(idx==3)과 같은 형태로 만드는 함수
int getN(int n, int idx){
    int result = n;
    for(int i = 1; i < idx; i++)
        result = result * 10 + n;
    
    return result;
}

// 찾는 number에 댛서 N과 사칙연산만 사용해 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 반환
int solution(int N, int number) {
    if(N == number)
        return 1;
    
    dp[1].insert(N);
    for(int i = 2; i<= 8; i++){ // N 사용횟수별 확인
        dp[i].insert(getN(N, i));   // 한 자리수
        
        for(int j = 1; j < i; j++){
            for(int k = 1; k < i; k++){
                if(j + k != i)  // 숫자 횟수가 일치할때만
                    continue;
                
                for(int a : dp[j]){
                    for(int b : dp[k]){
                        dp[i].insert(a + b);    // 더하기
                        
                        if(a - b > 0)
                            dp[i].insert(a - b);    // 빼기
                        
                        dp[i].insert(a * b);    //곱하기
                        
                        if(a/b > 0)
                            dp[i].insert(a/b);    //나누기
                    }
                }
            }              
        }
        // 만약 찾는 수가 있으면 사용횟수 반환
        if(dp[i].find(number) != dp[i].end())
            return i;
        
    }
    
    return -1;
}