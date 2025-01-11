// 수학, 브루트포스
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, num;
vector<int> v[30001];
priority_queue<pair<int, int>> q;

// 수 이어가기
int main(){
    cin >> N;
    for(int i = N; i >= 1; i--){
        v[i].push_back(N);
        v[i].push_back(i);
        int idx = 1;
        while(true){
            if(v[i][idx-1] - v[i][idx] < 0)
                break;

            v[i].push_back(v[i][idx-1] - v[i][idx]);
            idx++;
        }

        q.push({v[i].size(), i});
    }

    cout << q.top().first << "\n";
    for(int i = 0; i < q.top().first; i++)
        cout << v[q.top().second][i] << " ";
    cout << "\n";

    return 0;
}