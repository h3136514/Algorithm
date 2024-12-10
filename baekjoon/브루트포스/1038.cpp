#include <iostream>
#include <string>
#include <queue>

using namespace std;
int N;
long long decNum[1000001];
queue<pair<string, int>> q;

void bfs(){
    int cnt = 1;
    for(int i = 1; i < 10; i++){
        q.push({to_string(i), cnt});
        decNum[cnt++] = i;
    }

    while(!q.empty()){
        string s = q.front().first;
        int idx = q.front().second;
        q.pop();

        if(cnt > 1000000)
            break;
        
        // 감소하는 수 추가로 이어만들기
        for(int i = 0; i <= idx-1; i++){
            q.push({s + to_string(i), i});
            decNum[cnt++] = stoll(s + to_string(i));
        }
    }
}

// 감소하는 수
int main(){
    bfs();

    cin >> N;
    if(N != 0 && decNum[N] == 0)
        cout << "-1\n";
    else
        cout << decNum[N] << "\n";

    return 0;
}