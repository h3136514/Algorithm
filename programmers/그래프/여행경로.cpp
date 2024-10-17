// DFS
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int totalCNT, CNT = 1, visitied[10001][10001];
vector<string> tmp, v[10001];
unordered_map<string, int>  m;    // 공항별 인덱스 저장
bool checkPath = false;

void dfs(string s, int cnt){
        if(cnt == totalCNT){
            checkPath = true;
            return;
        }

        int currentIDX = m[s];
        for(int i = 0; i < v[currentIDX].size(); i++){
            string istr = v[currentIDX][i];
            int iidx = m[istr];
            if(!visitied[currentIDX][i]){
                visitied[currentIDX][i] = 1;
                tmp.push_back(istr);
                dfs(istr, cnt+1);
                
                // 길이 끊어진 경우(모든 항공권을 사용못한 경우)
                if(!checkPath){
                    visitied[currentIDX][i] = 0;
                    tmp.pop_back();
                }
            }

        }
        
}

// 주어진 항공권은 모두 사용하여 공항을 방문하라 (만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 반환)
vector<string> solution(vector<vector<string>> tickets) {
    // 정렬(가능한 경로가 여러개일 경우 알파벳 순서로 방문)
    sort(tickets.begin(), tickets.end());
    
    // 비행기 고유 인덱스 및 방향 등록
    for(vector<string> ticket : tickets){
        string a = ticket[0];
        string b = ticket[1];
        if(m.find(a) == m.end())
            m[a] = CNT++;
        if(m.find(b) == m.end())
            m[b] = CNT++;
        
        v[m[a]].push_back(b);
        totalCNT++;
    }
    
    tmp.push_back("ICN");
    dfs("ICN", 0);
    
    return tmp;
}