#include <iostream>
#include <map>
#include <vector>

using namespace std;
int N, D, K, C, cnt, result;
vector<int> v;
map<int, int> m;

// 회전 초밥
int main(){
    cin >> N >> D >> K >> C;

    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = 0; i < N; i++){ // 싸이클이 돌기 때문에 다시 추가
        v.push_back(v[i]);
    }

    for(int i = 0; i < K; i++){
        if(m.find(v[i]) == m.end()){
            cnt++;
        }
        m[v[i]]++;
    }

    if(m.find(C) == m.end())    // 쿠폰 추가
    {
        cnt++;
    }
    m[C]++;

    result = cnt;

    int s = 0;
    for(int e = K; e < v.size(); e++){
        if(m.find(v[e]) == m.end()){ // 초밥 종류 추가
            cnt++;
        }
        m[v[e]]++;


        m[v[s]]--;  
        if(m[v[s]] == 0){ // 초밥 종류 제거
            m.erase(v[s]);
            cnt--;
        }

        result = max(result, cnt);
        s++;
    }

    cout << result << "\n";

    return 0;
}