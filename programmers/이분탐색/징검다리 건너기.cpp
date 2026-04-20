// https://school.programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>

using namespace std;
int N, maxL, answer = 0;

int solution(vector<int> stones, int k) {
    N = stones.size();
    for(int i = 0; i < N; i++){
        maxL = max(maxL, stones[i]);
    }
    int s = 1, e = maxL;
    while(s <= e){
        int mid = (s + e)/2;
        
        int cnt = 0, maxCnt = 0;
        for(int i = 0; i < N; i++){
            if(stones[i] <= mid){ //  0 이하가 나오는 개수
                cnt++;
            }else{
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }
        maxCnt = max(maxCnt, cnt);
        
        if(k <= maxCnt){    // 사람을 너무 많이 뺐다
            e = mid - 1;
        }else{
            s = mid + 1;
            answer = max(answer, s); //주의
        }
    }
    
    return answer;
}