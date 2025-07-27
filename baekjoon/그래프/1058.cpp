#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, a, b, CNT, visitied[51];
vector<int> V[51];
string input;
queue<pair<int, int>> q;

void init(){
    for(int i = 1; i <= N; i++)
        visitied[i] = 0;
}

void bfs(int start){
    int currentCnt  = 0;
    q.push({start, 0});
    visitied[start] = 1;
    
    while(!q.empty()){
        int currentV = q.front().first;
        int currentDept = q.front().second;
        q.pop();

        if(currentDept >= 2)    // 친구의 친구까지
            continue;

        for(int i = 0; i < V[currentV].size(); i++){
            int iv =V[currentV][i];
            int idept = currentDept + 1;
            if(!visitied[iv]){
                visitied[iv] = 1;
                currentCnt++;
                q.push({iv, idept});
            }
        }
    }

    CNT = max(CNT, currentCnt);
}

// 친구
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> input;
        for(int j = 0; j < input.size(); j++){
            if(input[j] == 'Y'){
                V[i].push_back(j+1);
                V[j+1].push_back(i);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        bfs(i);
        init();
    }

    cout << CNT << "\n";

    return 0;
}