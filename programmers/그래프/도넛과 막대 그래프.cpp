// https://school.programmers.co.kr/learn/courses/30/lessons/258711
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
vector<int> answer;
vector<int> V[1000001];
int N, addV = 0, visitied[1000001], CNT = 0;
bool check = false;
queue<int> q, startV;
set<int> s, totallV;
map<int, int> in, out;

void init(){
    for(auto a : s)
        visitied[a] = 0;

    s.clear();
}

void bfs(int start){
    check = false;
    visitied[start] = 1;
    q.push(start);
    s.insert(start);
    
    while(!q.empty()){
        int currentV = q.front();
        q.pop();
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];
            
            if(visitied[iv]){
                check = true;
                continue;
            }
            
            s.insert(iv);
            visitied[iv] = 1;
            q.push(iv);
        }
    }
    
    
}

vector<int> solution(vector<vector<int>> edges) {
    answer.resize(4);
    
    for(vector<int> a : edges){
        V[a[0]].push_back(a[1]);
        totallV.insert(a[0]);
        totallV.insert(a[1]);
        
        out[a[0]]++;
        in[a[1]]++;
    }
     N = totallV.size();
    
    // 출발 점 찾기
    for(int a : totallV){   
        if(in.find(a) == in.end() && out[a] >=2){   // 들어오는 점은 0개 & 나가는 점은 2이상(그래프의 수의 합은 2이상이므로)
            addV = a;
            break;
        }
    }
    answer[0] = addV;
    
    // 출발 점과 연결 된 그래프 시작점 삽입
    for(int i = 0; i < V[addV].size(); i++){
        startV.push(V[addV][i]);
    }
    
    while(!startV.empty()){
        int start = startV.front();
        startV.pop();
        
        bfs(start);
        if(!check){
            answer[2]++;
        }else{
            int sum = 0;
            for(auto a : s){
                sum += V[a].size();
            }
            
            if(sum == s.size())
                answer[1]++;
            else
                answer[3]++;
        }
        
        init();
    }
    
    
    return answer;
}