// https://school.programmers.co.kr/learn/courses/30/lessons/12921
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int num[1000001], answer = 0;

void primeNumber(int n){
    num[1] = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if(num[i])
            continue;
        for(int j = i+i; j <= n; j += i){
            if(num[j])
                continue;
            num[j] = 1;
        }
    }
}

int solution(int n) {
    primeNumber(n);
    
    for(int i = 2; i <= n; i++)
        if(!num[i])
            answer++;
    
    return answer;
}