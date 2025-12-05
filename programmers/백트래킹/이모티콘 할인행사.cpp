// https://school.programmers.co.kr/learn/courses/30/lessons/150368
#include <string>
#include <vector>
#include <queue>

using namespace std;
int eCnt, sales[4] = {10, 20, 30, 40};
vector<int> answer;
vector<vector<int>> user;
vector<int> emoticon;
priority_queue<pair<int, int>> q;

void backtrack(int cnt, vector<int> v){
    if(cnt == eCnt){
        int totall = 0, totalCnt = 0;
        for(int i = 0; i < user.size(); i++){
            int bi = user[i][0];
            int price = user[i][1];
            int sum = 0;
            for(int j = 0; j < emoticon.size(); j++){
                if(v[j] >= bi){
                    sum += (emoticon[j] - emoticon[j]*(v[j]*0.01));
                }
            }
            if(sum >= price){
                totalCnt++;
            }else
                totall += sum;
        }
        
        q.push({totalCnt, totall});
        
        return;
    }
    
    for(int i = 0; i < 4; i++){
        v.push_back(sales[i]);
        backtrack(cnt+1, v);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    user = users;
    emoticon = emoticons;
    eCnt = emoticons.size();
    backtrack(0, {});
    
    answer.push_back(q.top().first);
    answer.push_back(q.top().second);
    
    return answer;
}