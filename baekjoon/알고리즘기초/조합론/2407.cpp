#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
string dp[102][102];

// 조합
int main(){
    int n, m;
    cin >> n >> m;
 
    string dp[102][102];
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                dp[i][j] = "1";
            else{
                int sum = 0; // 한 자리를 더한 값
                string n1 = dp[i - 1][j]; // 문자열1
                string n2 = dp[i - 1][j - 1]; // 문자열2
 
                // 두 문자열 수를 더하기
                // 두 문자열을 모두 처리하고 남은 자릿수 sum까지 처리했으면 종료 
                while(!n1.empty() || !n2.empty() || sum){
                    if(!n1.empty()){ 
                        sum += n1.back() - '0'; // 한 자리 더함
                        n1.pop_back(); // 한 자리 제거
                    }
                    if(!n2.empty()){
                        sum += n2.back() - '0'; // 한 자리 더함
                        n2.pop_back(); // 한 자리 제거 
                    }

                    // sum의 값 중 일의 자릿수 만 넣어주어함.
                    // 10의 나머지를 push해주고
                    dp[i][j].push_back((sum%10) + '0');
                    sum /= 10; // 10의 몫을 저장해주면 다음 자리수가 남음
                }


                // 수가 일의 자리부터 시작(반대로 뒤집움)
                reverse(dp[i][j].begin(), dp[i][j].end());
            }
        }
    }
    cout << dp[n][m];
    return 0;   
}