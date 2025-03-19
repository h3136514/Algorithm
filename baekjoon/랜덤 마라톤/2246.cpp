// 브루트포스
#include <iostream>
#include <vector>

using namespace std;
int N, CNT;
vector<pair<int, int>> v;

// 콘도 선정
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < N; i++){
        bool check = true;
        for(int j = 0; j < N; j++){
            // 자기 자신
            if(i == j){
                continue;
            }

            // X보다 바닷가에 더 가까운 콘도가 x보다 숙박비가 같거나 작고 X보다 숙박비가 더 싼 콘도가 X보다 바닷가에서 거리가 같거나 적을 경우
            if((v[i].first > v[j].first && v[i].second >= v[j].second) || (v[i].second > v[j].second && v[i].first >= v[j].first)){
                check = false;
                break;
            }
        }

        if(check){
            CNT++;
        }
    }

    cout << CNT << "\n";

    return 0;
}
