#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;
string a, b;
int dp[1001][1001];
vector<char> v;

// LCS 2
int main(){
    cin >> a;
    cin >> b;
    N = a.size();
    M = b.size();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[N][M] << "\n";
    if(dp[N][M] > 0){
        // 역추적(일치하는 문자)
        while(N > 0 && M > 0){
            if(dp[N][M] == dp[N-1][M])
                N--;
            else if(dp[N][M] == dp[N][M-1])
                M--;
            else{
                v.push_back(a[N-1]);
                N--;
                M--;
            }
        }

        for(int i = v.size()-1; i >= 0; i--){
            cout << v[i];
        }
        cout << "\n";
    }

    return 0;
}

/*

메모이제이션 시 string 배열을 쓰면 시간초과가 발생
이유: string을 대입하는 과정에서 string문자열 길이만큼 시간을 잡아먹기 때문
(여러 문자열을 연결할 때는 효율성을 고려해야 합)
string a, b;
string dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a;
    cin >> b;
    N = a.size();
    M = b.size();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + a[i-1];
            }else{
                dp[i][j] = (dp[i-1][j].size() > dp[i][j-1].size()) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    cout << dp[N][M].size() << "\n";
    if(dp[N][M].size() > 0)
        cout << dp[N][M] << "\n";

    return 0;
}

*/