#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> num;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    num.resize(n+2, 1);

    for(int i = 0; i < reserve.size(); i++){
        num[reserve[i]] ++;
    }
    
    for(int i = 0; i < lost.size(); i++)
        num[lost[i]]--;
    
    // 순서대로 정렬
    sort(lost.begin(), lost.end());
    // 여벌의 체육복을 가져온 학생이 양쪽에 있는지 확인
    for(int i = 0; i < lost.size(); i++){
        if(num[lost[i]] == 0){
            if(num[lost[i]-1] == 2){
                num[lost[i]-1] = 1;
                num[lost[i]] = 1;
            }else if(num[lost[i]+1] == 2){
                num[lost[i]+1] = 1;
                num[lost[i]] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(num[i])
            answer++;
    }
    
    return answer;
}