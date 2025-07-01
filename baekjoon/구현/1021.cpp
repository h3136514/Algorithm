#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
int N, M, pos, answer = 0;
deque<int> dq;

// 회전하는 큐
int main(){
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        dq.push_back(i);
    }
    
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        
        // 목표 원소의 위치 찾기
        for(int j = 0; j < dq.size(); j++){
            if(dq[j] == target){
                pos = j;
                break;
            }
        }
        
        // 왼쪽 회전과 오른쪽 회전 중 더 적은 횟수 선택
        int leftR = pos;
        int rightR = dq.size() - pos;
        
        if(leftR <= rightR){
            // 왼쪽으로 회전 (2번 연산)
            for(int j = 0; j < leftR; j++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            answer += leftR;
        } else {
            // 오른쪽으로 회전 (3번 연산)
            for(int j = 0; j < rightR; j++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            answer += rightR;
        }
        
        // 1번 연산: 첫 번째 원소 제거
        dq.pop_front();
    }
    
    cout << answer << "\n";
    
    return 0;
}