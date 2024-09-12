#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 51
using namespace std;
int N, M, city[MAX][MAX], num[14], visitied[14];
vector<pair<int, int>> house, chicken;
priority_queue<int> sumDist;

// 치킨 거리 계산(조합중 가장 작은 치킨 거리 합)
void distCal() {
    int sum = 0;

    for(int i = 0; i < house.size(); i++) {
        int x = house[i].first;
        int y = house[i].second;

        int sumMin= MAX*2;
        for(int j = 0; j < M; j++) {
            int idx = num[j];

            int cx = chicken[idx].first;
            int cy = chicken[idx].second;
            int dist = abs(x-cx) + abs(y-cy);
            if(sumMin > dist)
                sumMin = dist;
        }

        sum += sumMin;
    }

    sumDist.push(-sum);
}

// M개의 치킨 집 조합 찾기
void dfs(int ago, int cnt) {
    if(cnt == M) {
        distCal();
        
        return;
    }

    for(int i = ago; i < chicken.size(); i++) {
        if(!visitied[i]){
            visitied[i] = 1;
            num[cnt] = i;
            dfs(i, cnt + 1);
            visitied[i] = 0;
        }
        
    }

}

// 치킨집 중에서 최대 M개를 고르고, 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하여라
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1)
                house.push_back({j, i});
            else if(city[i][j] == 2)
                chicken.push_back({j, i});
        }
    }

    dfs(0, 0);

    cout << -sumDist.top() << "\n";

    return 0;
}

