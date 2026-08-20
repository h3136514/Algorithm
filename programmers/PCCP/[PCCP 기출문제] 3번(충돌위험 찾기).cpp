#include <string>
#include <vector>
#include <map>

using namespace std;
map<pair<int, pair<int, int>>, int> m; // 시간과 위치값
int answer = 0;

void update(pair<int, pair<int, int>> key){
    if(m.find(key) != m.end())
        m[key]++;
    else
        m[key] = 1;
}


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(auto route : routes){
        int time = 0;
        for(int j = 0; j < route.size()-1; j++){
            int s = route[j]-1;
            int e = route[j+1]-1;
            
            int y = points[s][0];
            int x = points[s][1];
            
            int dirY = points[e][0] - y > 0 ? 1 : -1;
            int dirX = points[e][1] - x > 0 ? 1 : -1;
            
            if(j == 0)
                 update({time++, {y, x}});
            
            //Y좌표부터 목표 좌표에 맞추기
            while(y != points[e][0]){
                y += dirY;
                update({time++, {y, x}});
            }
            while(x != points[e][1]){
                x += dirX;
                update({time++, {y, x}});
            }            
        }
    }
    for(auto log : m){
        if(log.second > 1)
            answer++;
    }
    
    return answer++;
}