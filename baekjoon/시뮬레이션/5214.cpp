#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 987654321
using namespace std;
int N, K, M, num, visitied[100001], visitiedHifer[1001], result = INF;
vector<vector<int>> hifer;
vector<int> V[100001];
queue<pair<int, int>> q;
set<int> s;
bool check = false;

void bfs(int start){
    visitied[start] = 1;
    for(int i = 0; i < V[start].size(); i++){
        q.push({V[start][i], 0});
        visitiedHifer[V[start][i]] = 1;
    }

    while(!q.empty()){
        int currentIdx = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        for(int i = 0; i < hifer[currentIdx].size(); i++){  //하이퍼튜브를 정점으로 함
            int iv = hifer[currentIdx][i];
            int icnt = currentCnt + 1;

            if(iv == N){
                check = true;
                if(N == 1)
                    result = icnt;
                else
                    result = icnt+1;
                break;
            }

            if(!visitied[iv]){
                visitied[iv] = 1;
                for(int j = 0; j < V[iv].size(); j++){
                    int iIdx = V[iv][j];
                    if(!visitiedHifer[iIdx]){
                        visitiedHifer[iIdx] = 1;
                        q.push({iIdx, icnt});
                    }
                }
            }
        }
        
        if(check)
            break;
    }
}

// 환승
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cin >> K;
    cin >> M;
    for(int i = 0; i < M; i++){
        vector<int> tmp = {};

        for(int j = 0; j < K; j++){
            cin >> num;
            s.insert(num);      // 싸이클 제외
        }

        for(int n : s){
            V[n].push_back(i);
            tmp.push_back(n);
        }
        s.clear();

        hifer.push_back(tmp);
    
    }

    bfs(1);

    if(!check)
        result = -1;

    cout << result << "\n";

    return 0;
}