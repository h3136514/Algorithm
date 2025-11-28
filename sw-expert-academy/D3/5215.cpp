// 햄버거 다이어트
#include <iostream>
#include <vector>

using namespace std;
int T, N, L, dp[21][10002];
vector<pair<int, int>> v;

void init(){
    v.clear();

    for(int j = 1; j <= N; j++){
        for(int c = 1; c <= L; c++){
            dp[j][c] = 0;
        }
    }
}

int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N >> L;

        v.resize(N);
        for(int j = 0; j < N; j++){
            cin >> v[j].first >> v[j].second;
        }

        for(int j = 1; j <= N; j++){
            int flavor = v[j-1].first;
            int calor = v[j-1].second;

            for(int c = 1; c <= L; c++){
                if(calor <= c){
                    dp[j][c] = max(dp[j-1][c], dp[j-1][c-calor] + flavor);
                }else
                    dp[j][c] = dp[j-1][c];
            }
        }

        cout <<"#" << i <<" " << dp[N][L] << "\n";
        init();
    }

    return 0;
}