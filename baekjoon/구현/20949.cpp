// 정렬
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int N, W, H;
priority_queue<pair<long long, int>> q;

// 효정과 새 모니터
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> W >> H;
        long long accurate = pow(W, 2)+pow(H, 2);
        q.push({accurate, -i});
    }

    while(!q.empty()){
        cout << -q.top().second + 1 << "\n";
        q.pop();
    }

    return 0;
}