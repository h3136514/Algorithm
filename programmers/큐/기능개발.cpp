#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> q; // 배포를 기다리는 기능(작업완료)
int cnt, totalCnt;    //현재 배포된 수, 총 배포된 수
int num[101]; //작업완료 유무

//배포마다 몇 개의 기능이 배포되는지를 반환(단, 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포, 시간복잡도 : O(NlogN))
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(totalCnt < progresses.size()){
        for(int i = totalCnt; i < progresses.size(); i++){
            progresses[i] += speeds[i];
            if(progresses[i] >= 100 && !num[i]){
                q.push(-i);  // push: O(log n)
                num[i] = 1;
            }
            
        }
        if(q.empty())
            continue;
        //선행 기능 작업이 완료X
        if(totalCnt != - q.top())
            continue;
            
        cnt = 0;
        while(!q.empty()){
            if(totalCnt == - q.top()){  //배포될 순서 일치(배포 안된 것 중 맨 앞)
                totalCnt++;
                cnt++;
                q.pop();    // pop: O(log n)
            }else //선행 기능 작업이 완료X
                break;
        }
        
        answer.push_back(cnt);   
    }   
    
    return answer;
}

#include <iostream>
int main()
{ 
    vector<int> arr = solution({93, 30, 55}, {1, 30, 5});   // 2 1
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
// 각 기능의 배포 예정일을 미리 구해서 풀기(선행작업이 완료되지 않은 작업을 따로 보관안하고 푸는 구현법), 시간복잡도 : O(N))

#include <cmath>

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n); 

    //각 작업에 대한 완료까지 남은 일수 계산
    for (int i = 0; i < n; ++i) {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

   int count = 0; //배포 될 작업의 수
    int max_day = days_left[0]; // 현재 배포될 작업 중 가장 늦게 배포될 작업의 가능일
    

    for (int i = 0; i < n; ++i) {
        if (days_left[i] <= max_day) { //배포 가능일이 가장 늦은 배포일보다 빠르면
            count++;
        } else { //배포 예정일이 기준 배포일보다 느리면
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count); //마지막으로 카운트된 작업들을 함께 배포
    return answer;
}
*/