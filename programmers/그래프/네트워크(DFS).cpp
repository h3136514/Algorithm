#include <string>
#include <vector>

using namespace std;
int visitied[200];
vector<vector<int>> v;

void dfs(int start){
    if(visitied[start])
        return;
    visitied[start] = 1;
    
    for(int j = 0; j < v[start].size(); j++){
        int contact = v[start][j];
        if(contact && !visitied[j]){
            dfs(j);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    v = computers;
    
    for(int i = 0; i < n; i++){
        if(!visitied[i]){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}