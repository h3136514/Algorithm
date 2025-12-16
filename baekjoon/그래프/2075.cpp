// https://www.acmicpc.net/problem/2075
// 우선순위 큐(메모리 초과 조심)
#include <iostream>
#include <queue>

using namespace std;
int N, num;
priority_queue<int> q;

// N번째 큰 수
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i <N*N; i++){
        cin >> num;
        q.push(-num);
    
        if(q.size() > N){
            q.pop();
        }
    }

    cout << -q.top() << "\n";

    return 0;
}