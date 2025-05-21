// 정렬
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N, M, a, b;
char c;
string s;
priority_queue<pair<int, pair<int, char>>> q;

// 키보드 이벤트
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        q.push({-b, {-a, c}});
    }

    while(!q.empty()){
        s += q.top().second.second;
        q.pop();
    }

    cout << s << "\n";

    return 0;
}