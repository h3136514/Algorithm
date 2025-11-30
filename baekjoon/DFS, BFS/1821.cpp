#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, F, ago, visitied[11];
vector<int> result;
queue<int> q, tmpQ;

void dfs(vector<int> tmp){
    if(tmp.size() >= N){
        if(!result.empty())
            return;

        for(int i = 0; i < tmp.size(); i++){
            q.push(tmp[i]);
        }

        while(q.size() > 1){
            ago = q.front();
            q.pop();

            while(!q.empty()){
                tmpQ.push(ago + q.front());
                ago = q.front();
                q.pop();
            }

            q = tmpQ;
            while(!tmpQ.empty())
                tmpQ.pop();
        }
        
        if(q.front() == F){
            result = tmp;
        }
        while(!q.empty())
            q.pop();

        return;
    }

    for(int i = 1; i <= N; i++){
        if(!visitied[i]){
            visitied[i] = 1;
            tmp.push_back(i);
            dfs(tmp);
            tmp.pop_back();
            visitied[i] = 0;
        }
    }
}

// 수들의 합 6 
int main(){
    cin >> N >> F;

    dfs({});

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
