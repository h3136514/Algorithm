// https://school.programmers.co.kr/learn/courses/30/lessons/150369?language=cpp
#include <string>
#include <vector>

using namespace std;
long long answer = 0;
int d = 0, p = 0, cnt = 0;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    for(int i = n - 1; i >= 0; i--){
        d -= deliveries[i];
        p -= pickups[i];
        
        while(true){
            if(d >= 0 && p >= 0)
                break;
            d += cap;
            p += cap;
            cnt++;
        }
        
        answer += (i+1)*2*cnt;
        cnt = 0;
    }
    
    return answer;
}