#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T, N, a, b, maxV;
vector<pair<int, int>> v;

// 신입사원
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end());
        int cnt = 1;
        maxV = v[0].second; // 최대 면접순위 지정
        for(int i = 1; i < N; i++){
            if(v[i].second < maxV){ // 최대 면접 순위보다 높으면 신입사원 포함
                cnt++;
                maxV = v[i].second;
            }
        }

        cout << cnt << "\n";

        v.clear();
    }
}