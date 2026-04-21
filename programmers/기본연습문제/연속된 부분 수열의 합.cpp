// https://school.programmers.co.kr/learn/courses/30/lessons/178870
#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int N, sum, minL = 1000000;

vector<int> solution(vector<int> sequence, int k) {
    answer.resize(2);
    N = sequence.size();
    
    int s = 0;
    for(int e = 0; e < N; e++){
        sum += sequence[e];
        
        if(sum == k && e-s < minL){
            minL = e-s;
            answer[0] = s, answer[1] = e;
            continue;
        }
        
        if(sum > k){
            while(s < e){
                sum -= sequence[s++];
                if(sum <= k){
                    break;                    
                }
            }
            if(sum == k && e-s < minL){
                minL = e-s;
                answer[0] = s, answer[1] = e;
            }
            
        }
    }
    
    
    return answer;
}