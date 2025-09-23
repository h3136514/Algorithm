#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N, M, a, b, c, startV, endV, dp[1001];
vector<pair<int, int>> V[1001];
vector<int> result;
priority_queue<pair<int, pair<int, vector<int>>>> q;

void dijsktra(){
    q.push({0, {startV, {startV}}});
    dp[startV] = 0;

    while(!q.empty()){
        int currentCost = -q.top().first;
        int currentV = q.top().second.first;
        vector<int> currentVec = q.top().second.second;
        q.pop();

        if(dp[currentV] < currentCost)
            continue;
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].second;
            int icost = currentCost + V[currentV][i].first;
            vector<int> iVec(currentVec);

            if(dp[iv] > icost){
                dp[iv] = icost;
                iVec.push_back(iv);
                if(iv == endV){
                    result = iVec;
                }

                q.push({-icost, {iv,  iVec}});
                iVec.pop_back();
            }
        }
    }

}

// 최소비용 구하기 2
int main(){
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        V[a].push_back({c, b});
    }
    cin >> startV >> endV;

    for(int i = 1; i <= N; i++){
        dp[i] = INF;
    }

    dijsktra();

    cout << dp[endV] << "\n";
    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
