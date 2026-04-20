// https://school.programmers.co.kr/learn/courses/30/lessons/12904
#include <iostream>
#include <string>
using namespace std;
int N, answer=1;

int solution(string s){
    N = s.size();
    if(N == 1)
        return 1;
    
    for(int i = 0; i < N; i++){
        // 1. 홀수 팰린드롬 (ex: aba)
        int cnt = 1;
        int start = i-1, end = i+1;
        while(start >= 0 && end < N){
            if(s[start] == s[end]){
                start--, end++;
                cnt += 2;
            }else
                break;
        }
        answer = max(answer, cnt);
        
        // 2. 짝수 팰린드롬 (ex: abba)
        cnt = 0;
        start = i, end = i+1;
        while(start >= 0 && end < N){
            if(s[start] == s[end]){
                start--, end++;
                cnt += 2;
            }else
                break;
        }
        
        answer = max(answer, cnt);
    }

    return answer;
}