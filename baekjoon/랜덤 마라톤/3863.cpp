// 구현, 브루트포스
#include <iostream>
#include <vector>

using namespace std;
int N, M, sou, dest, start, dura;
vector<pair<int, int>> v;

// 행복한 전화 통화
int main(){
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;
        
        for(int i = 0; i < N; i++){
            cin >> sou >> dest >> start >> dura;
            
            v.push_back({start, start+dura});
        }

        for(int i = 0; i < M; i++){
            cin >> start >> dura;

            int cnt = 0;
            for(int j = 0; j < v.size(); j++){
                // 세가지 구간을 확인(겹치는 구간이 조금 있을때(두가지 경우), 전부 겹칠때)
                if((start >= v[j].first && start < v[j].second ) ||((start+dura) > v[j].first && (start+dura) <= v[j].second ) || (start <= v[j].first && (start+dura) >= v[j].second ))
                    cnt++;
            }

            cout << cnt << "\n";
        }

        v.clear();

    }

    return 0;
}