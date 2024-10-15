#include <string>
#include <vector>
#include <queue>

using namespace std;
int cnt, num[101];
queue<int> q;
priority_queue<int> prioritieQ;
 
// 현재 실행 대기 큐(Queue)에 있는 프로세스의 중요도가 순서대로 담긴 배열과, 몇 번째로 실행되는지 알고싶은 프로세스의 위치가 주어질 때, 해당 프로세스가 몇 번째로 실행되는지(특정 프로세스가 몇 번째로 실행되는지)
int solution(vector<int> priorities, int location) {
    for(int i = 0; i < priorities.size(); i++){
        q.push(i);
        prioritieQ.push(priorities[i]); // 우선순위 차례를 저장
        num[i] = priorities[i];  // 원소별 우선순위 표시
    }
    
    while(!q.empty()){
        int target = q.front();
        q.pop();
        int turn = prioritieQ.top();

        if(turn == num[target]){    // 해당 우선순위 차례라면
            cnt++;
            prioritieQ.pop();
            if(target == location)
                break;
        }else{  // 아니면(다시 넣음)
            q.push(target);
        }
    }
    
    return cnt;
}