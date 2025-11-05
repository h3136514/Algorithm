// 우선순위 큐
#include <iostream>
#include <queue>

using namespace std;
int N, K, m, v, c;
long long sum;
priority_queue<pair<int, int>> crystal;
priority_queue<int> q, C;

// 보석 도둑
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> m >> v;
        crystal.push({-m, v});
    }
    for(int i = 0; i < K; i++){
        cin >> c;
        C.push(-c);
    }

    while(!C.empty()){
        int currentM = -C.top();
        C.pop();

        while(!crystal.empty()){
            int im = -crystal.top().first;
            int iv = crystal.top().second;
            crystal.pop();

            if(currentM >= im){
                q.push(iv);
            }else{
                crystal.push({-im, iv});
                break;
            }
        }

        if(!q.empty()){
            sum += q.top();
            q.pop();
        }
    }

    cout << sum << "\n";

    return 0;
}