#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, a, b, visitied[501][501];
string s[501];
vector<pair<string, int>> dp[501];

// 3루수는 몰라
int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
        dp[i].resize(N);
    }

    // 초기 값 설정
    if(s[0][0] == 'M')
        dp[0][0] = {"M", 0};
    // 맨 첫번째 줄
    for(int i = 1; i < N; i++){
        pair<string, int> p1 = dp[i-1][0];
        if(s[i][0] == 'M'){
            dp[i][0] = {"M", p1.second};
        }else if(s[i][0] == 'O' && p1.first == "M"){
            dp[i][0] = {"MO", p1.second};
        }else if(s[i][0] == 'L' && p1.first == "MO"){
            dp[i][0] = {"MOL", p1.second};
        }else if(s[i][0] == 'A' && p1.first== "MOL"){
            dp[i][0] = {"", p1.second + 1};
        }else{
            dp[i][0] = {"", p1.second};
        }
        
        pair<string, int> p2 = dp[0][i-1];
        if(s[0][i] == 'M'){
            dp[0][i] = {"M", p2.second};
        }else if(s[0][i]  == 'O' && p2.first == "M"){
            dp[0][i] = {"MO", p2.second};
        }else if(s[0][i] == 'L' && p2.first == "MO"){
            dp[0][i] = {"MOL", p2.second};
        }else if(s[0][i] == 'A' && p2.first == "MOL"){
            dp[0][i] = {"", p2.second + 1};
        }else{
            dp[0][i] = {"", p2.second};
        }
    }

    // x-1, y-1 값 비교(최댓값으로 연결)
    for(int i = 1; i < N; i++){
         for(int j = 1; j < N; j++){
            pair<string, int> p1;
            if(s[i][j] == 'M'){
                p1 = {"M", dp[i-1][j].second};
            }else if(s[i][j] == 'O' && dp[i-1][j].first == "M"){
                p1 = {"MO", dp[i-1][j].second};
            }else if(s[i][j] == 'L' && dp[i-1][j].first == "MO"){
               p1= {"MOL", dp[i-1][j].second};
            }else if(s[i][j] == 'A' && dp[i-1][j].first== "MOL"){
                p1= {"", dp[i-1][j].second + 1};
            }else{
                p1 = {"", dp[i-1][j].second};
            }
            
            pair<string, int> p2;
            if(s[i][j] == 'M'){
                p2 = {"M", dp[i][j-1].second};
            }else if(s[i][j]  == 'O' && dp[i][j-1].first == "M"){
                p2 = {"MO", dp[i][j-1].second};
            }else if(s[i][j] == 'L' && dp[i][j-1].first == "MO"){
                p2 = {"MOL", dp[i][j-1].second};
            }else if(s[i][j] == 'A' && dp[i][j-1].first == "MOL"){
                p2 = {"", dp[i][j-1].second + 1};
            }else{
                p2 = {"", dp[i][j-1].second};
            }

             if(p1.second > p2.second){
                 dp[i][j] = p1;
             }else if(p1.second < p2.second){
                 dp[i][j] = p2;
             }else{
                 if(p1.first.size() > p2.first.size())
                    dp[i][j] = p1;
                 else
                    dp[i][j] = p2;
             }
         }
    }

    cout << dp[N-1][N-1].second << "\n";
    
    return 0;
}