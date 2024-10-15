#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
int currentWeight, CNT;

// 트럭 여러 대가 일차선 다리를 정해진 순으로 건너려 한다. 트럭 수, 다리가 견딜 수 있는 무게, 트럭 별 무게가 주어질 때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    for(int truck : truck_weights){
        CNT++;
        if(q.empty()){  //비워 있으면 지나감
            q.push({truck, bridge_length+CNT});
            currentWeight += truck;
            continue;
        }
        if(q.front().second == CNT){  // 현재 맨 앞 트럭이 지나감
            currentWeight -= q.front().first;   // 무게 갱신
            q.pop();    // 트럭 \제거
        }
        
        if(weight >= currentWeight + truck){    //현재 다리 무게가 이번 순서이 트럭을 견딜 수 있으면 추가
            q.push({truck, bridge_length+CNT});
            currentWeight += truck;
            
        }else{
            currentWeight += truck;
            while(weight < currentWeight){  // 이번 순서이 트럭이 진입 할 수 있을 때까지 기다림
                CNT = q.front().second;
                currentWeight -= q.front().first;
                q.pop();
            }
          
            q.push({truck, bridge_length+CNT});
        }
    }
    
    // 모든 다리에 있는 트럭을 보냄
    while(!q.empty()){
        CNT = q.front().second;
        q.pop();
    }
    
    return CNT;
}