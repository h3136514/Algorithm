#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>    // floor() (내림 함수)

using namespace std;
int N, num, manyCnt, manyNum;
double sum;
vector<int> v;
priority_queue<pair<int, int>> q;
map<int, int> m;

// 통계학
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        sum += num;
        v.push_back(num);
        m[num]++;
    }

    sort(v.begin(), v.end());

    // 산술평균 구하기
    cout << floor(sum/N + 0.5) << "\n"; // 반올림
    
    // 중앙값 구하기
    if(N == 1)
        cout << v[0] << "\n";
    else
        cout << v[N/2] << "\n";


    // 최빈값 구하기
    for(auto cnt : m){
        q.push({cnt.second, -cnt.first});
    }
    manyCnt = q.top().first;
    manyNum = -q.top().second;
    q.pop();
    if(!q.empty()){
        if(manyCnt == q.top().first)
            manyNum = -q.top().second;
    }
    
    cout << manyNum << "\n";

    // 범위
    cout << v[N-1] - v[0] << "\n";

    return 0;
}