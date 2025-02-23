// 구현, 시물레이션
#include <iostream>
#include <vector>

using namespace std;
int T, W, N, sum;
long long dist;
vector<pair<int, int>> v;

void init(){
    sum = 0;
    dist = 0;
    v.clear();
}

// 쓰레기 수거
int main(){
    cin >> T;
    
    while(T--){
        cin >> W >> N;
        v.resize(N);

        for(int i = 0; i < N; i++){
            cin >> v[i].first >> v[i].second;
        }

        dist = v[0].first;
        sum = v[0].second;
        if(sum >= W){
            dist += v[0].first;
            sum = 0;
        }

        for(int i = 1; i < N; i++){
            if(sum == 0)
                dist += v[i].first; // 쓰레기장에서 이동
            else
                dist += v[i].first - v[i-1].first;   // 다른 지점에서 이동
            
            if(sum + v[i].second > W){  // 쓰레기창 용량 넘침
                dist += v[i].first*2;
                sum = v[i].second;
            }else if(sum + v[i].second == W){   // 쓰레기창 용량 꽉참
                dist += v[i].first;
                sum = 0;
            }else
                sum += v[i].second;
        }
        // 마지막 지점 복귀 여부
        if(sum != 0)
            dist += v[N-1].first;

        cout << dist << "\n";

        init();
    }

    return 0;
}
