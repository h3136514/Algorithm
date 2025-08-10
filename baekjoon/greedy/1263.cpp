#include <iostream>
#include <queue>

using namespace std;
int N, t, s, result;
priority_queue<pair<int, int>> q;

// 시간 관리
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t >> s;
        q.push({s, t});
    }

    result = q.top().first - q.top().second;
    q.pop();

    while(!q.empty()){
        t = q.top().second;
        s = q.top().first;
        q.pop();

        if(result > s){
            result = s - t;
        }else
            result -= t;

        
        if(result < 0){
            result = -1;
            break;
        }
    }

    cout << result << "\n";

    return 0;
}
