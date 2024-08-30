#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int N, M, num[9], arr[9], visited[9];
map <vector<int>, bool> agos;

void dfs(int cnt) {
    if(cnt == M) {
        vector<int> check;
        for(int i = 0; i < M; i++) {
            check.push_back(arr[i]);
        }
        // 중복되는 수열인지 확인
        if(agos.find(check) == agos.end()) {
            agos[check] = true;
            
            for(int i = 0; i < M; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }

        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            arr[cnt] = num[i];
            visited[i] = 1;
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

// N개의 자연수와 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하여라(단, 중복되는 수열을 여러 번 출력하면 안되며, 수열은 사전 순으로 증가하는 순서야 됨)
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    sort(num, num + N);

    dfs(0);

    return 0;
}