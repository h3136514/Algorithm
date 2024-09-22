#include <vector>
#include <queue>

using namespace std;
priority_queue<pair<double, int>> q;    // 무게당 가치, 무게를 내림차순으로 저장

// items: [무게, 가치] 원소(짐)들, weight_limit : 배낭의 수용 무게 가 주어질 때 가방의 무게를 초과하지 않으면서 가방에 들어 있는 짐의 가치가 최대가 되도록 하는 총 가치의 합(짐을 쪼갤 수 있다.) 
double solution(vector<vector<double>> items, double weight_limit) {
    int n = items.size();   // 전체 원소 수

    for(int i = 0; i < n; i++) {
        int weight = items[i][0];   // 무게
        double value = items[i][1] / weight;    // 무게당 가치

        q.push({value, weight});
    }

    double sum_value = 0;   // 총 가치의 합
    while(weight_limit > 0) {
        int current_weight = q.top().second;
        double current_value = q.top().first;
        q.pop();

        if(weight_limit >= current_weight){ // 남은 무게 한도 내에서 물건을 통째로 선택가능할 경우
            weight_limit -= current_weight;
            sum_value += current_weight * current_value;
        } else {    // 물건을 쪼개는 경우
            sum_value += weight_limit * current_value;  // 남은 무게 * 물건 가치를 더함
            weight_limit = 0;
        }

    }
  
    return sum_value;
}

// 테스트 코드 
#include <iostream>

void init() {
    while(!q.empty())
        q.pop();
}

int main()
{
    cout << solution({{10, 19}, {7, 10}, {6, 10}}, 15) << endl; //출력값 : 27.3333
    init();
    cout << solution({{10, 60}, {20, 100}, {30, 120}}, 50) << endl; //출력값 : 240
  
    return 0;
}