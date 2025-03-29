// 수학
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K, f, d;
vector<pair<int, int>> v;

// 점심시간 레이스
int main(){
    cin >> N >> M >> K;
    for(int i = 1; i <= K; i++){
        cin >> f >> d;
        v.push_back({M+1-d+f-1, i});
    }

    sort(v.begin(), v.end());

    cout << v[0].second << "\n";

    return 0;
}