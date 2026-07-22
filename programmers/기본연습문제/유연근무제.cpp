// https://school.programmers.co.kr/learn/courses/30/lessons/388351?language=cpp
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<int> schedule;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    for(auto workTime : schedules){
        int num = 0;
        if((workTime%100+10)/60 == 1){
            num = (workTime/100 +1)*100 + (workTime%100+10)%60;
        }else{
            num = (workTime +10);
        }
        schedule.push_back(num);
    }
    
    for(int j = 0; j < timelogs.size(); j++){
        bool check = true;
        for(int i = 0; i < timelogs[j].size(); i++){
            int currentDay = (i + startday - 1) % 7 + 1;
            if(currentDay == 6 || currentDay == 7)
                continue;
            else{
                if(timelogs[j][i] > schedule[j]){
                    check = false;
                    break;
                }
            }
        }
        
        if(check)
            answer++;
    }
    
    return answer;
}