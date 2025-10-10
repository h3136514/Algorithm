#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, answer = 0;

int solution(vector<int> citations) {
    N = citations.size();
    sort(citations.begin(), citations.end());
    
    for(int i = N; i >= 1; i--){
        int cnt = 0;
        for(int j = citations.size() -1; j >= 0; j--){
            if(citations[j] >= i){
                cnt++;
                continue;
            }
            
            break;
        }
        
        if(cnt >= i){
            answer = i;
            break;
        }
    }
    
    return answer;
}