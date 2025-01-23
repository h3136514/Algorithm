// 구현, 정렬
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int T, N, cnt;
string name;
priority_queue<pair<int, string>> q;

void init(){
    while(!q.empty())
        q.pop();
}

// Yangjojang of The Year 
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> name >> cnt;
            q.push({cnt, name});
        }

        cout << q.top().second << "\n";

        init();
    }

    return 0;
}