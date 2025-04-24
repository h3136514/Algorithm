#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, num, maxSum, chicken[3];
vector<int> v[30];

void dfs(int idx, int cnt){
    if(cnt == 3){
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += max({v[i][chicken[0]], v[i][chicken[1]], v[i][chicken[2]]});
        }

        maxSum = max(maxSum, sum);
        return;
    }

    for(int i = idx; i < M; i++){
        chicken[cnt] = i;
        dfs(i+1, cnt+1);
    }
}

// 치킨치킨치킨
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num;
            v[i].push_back(num);
        }
    }
    
    dfs(0, 0);

    cout << maxSum << "\n";

    return 0;
}
