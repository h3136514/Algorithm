// https://www.acmicpc.net/problem/2623
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int N, M, n, num, cnt, visitied[1001], CNT[1001];
vector<int> tmp, result;
queue<int> q[1001];

// 음악프로그램
int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> num;
            CNT[num]++;
            q[i].push(num);
        }
    }

    for(int i = 1; i <= N; i++ ){
        if(CNT[i] == 0)
            tmp.push_back(i);
    }

    while(cnt != N){
        vector<pair<int, int>> v;
        map<int, int> m;

        for(int i = 1; i <= M; i++){
            while(!q[i].empty() && visitied[q[i].front()]){
                q[i].pop();
            }
            if(q[i].empty())
                continue;
            
            v.push_back({i, q[i].front()});
            m[q[i].front()]++;
        }
        if(v.empty())
            break;
        
        bool check = false;
        for(int i = 0; i < v.size(); i++){
            int idx = v[i].first;
            int value = v[i].second;

            if(CNT[value] == m[value]){
                q[idx].pop();
                CNT[value] -= m[value];
                result.push_back(value);
                cnt++;
                visitied[value] = 1;
                check = true;
                break;
            }
        }
       
        if(!check)
            break;

        v.clear();
        m.clear();
    }

    if(!tmp.empty()){
        for(int i = 0; i < tmp.size(); i++){
            result.push_back(tmp[i]);
            cnt++;
        }
    }

    if(cnt != N)
        cout << "0\n";
    else{
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }
}