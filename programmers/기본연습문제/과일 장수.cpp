#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(int k, int m, vector<int> score) {
    sort(score.rbegin(), score.rend());
    
    for(int i = 0; i < score.size(); i+= m){
        int idx =i+m-1;
        if(score[idx] > k)
            continue;
        
        answer += score[idx]*m;
    }
    
    return answer;
}