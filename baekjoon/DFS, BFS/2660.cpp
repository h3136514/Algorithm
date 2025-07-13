#include <iostream>
#include <vector>
#include <queue>

using namespace std;
short N, score[51], a, b, targetCNT, targetScore;
bool visitied[51];
vector<short> V[51];
queue<pair<short, short>> q;

void init(){
    for(int i = 1; i <= N; i++)
        visitied[i] = false;
}

void bfs(short start){
    q.push({start, 0});
    visitied[start] = true;

    while(!q.empty()){
        int currentV = q.front().first;
        int currentScore = q.front().second;
        q.pop();
        
        if(score[start] < currentScore)
            score[start] = currentScore;

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];

            if(!visitied[iv]){
                visitied[iv] = true;
                q.push({iv, currentScore+1});
            }
        }

    }

    targetScore = min(targetScore, score[start]);
}

// 회장뽑기
int main(){
    cin >> N;
    while(true){
        cin >> a >> b;
        if(a== -1)
            break;

        V[a].push_back(b);
        V[b].push_back(a);
    }

    targetScore = N;
    for(int i = 1; i <= N; i++){
        bfs(i);

        init();
    }

    for(int i = 1; i <= N; i++){
        if(targetScore == score[i])
            targetCNT++;
    }

    cout << targetScore << " " << targetCNT << "\n";
    for(int i = 1; i <= N; i++){
        if(targetScore == score[i])
            cout << i << " ";
    }

    return 0;
}