#include <string>
#include <vector>

#define INF 1000000000000000000
using namespace std;
long long startT, endT = INF, totalTime = INF;

long long solution(int n, vector<int> times) {
    long long answer = INF;
    
    while(startT <= endT){
        long long mid = (startT + endT) / 2;
        
        long long cnt = 0;
        for(int i = 0; i < times.size(); i++){
            cnt += mid/times[i];
        }
        
        if(cnt >= n){
            answer = min(answer, mid);
            endT = mid - 1;
        }else{
            startT = mid + 1;
        }
        
    }
    
    return answer;
}