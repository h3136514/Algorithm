// https://school.programmers.co.kr/learn/courses/30/lessons/12987
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, answer = 0;

int solution(vector<int> A, vector<int> B) {
    N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int idx = 0;
    for(int i = 0; i < N; i++){
        while(idx < N){
            if(A[i] < B[idx]){
                answer++;
                idx++;
                break;
            }
            idx++;
        }
        
        if(idx == N)
            break;
    }
    
    return answer;
}