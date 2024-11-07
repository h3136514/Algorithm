#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, K, CNT, alpha[26];
string str;
vector<string> v;

// 백트래킹
void dfs(int cnt, int idx){
    if(cnt == K){
        int checkCnt = 0;
        for(int i = 0; i < v.size(); i++){
            bool check = false;
            for(int j = 4; j < v[i].size() - 4; j++){
                int num = v[i][j] - 'a';
                if(!alpha[num]){
                    check = true;
                    break;
                }
            }

            if(!check)
                checkCnt++;
        }

        CNT = max(CNT, checkCnt);
        return;
    }

    for(int i = idx; i < 26; i++){
        if(alpha[i])
            continue;
        
        alpha[i] = 1;
        dfs(cnt + 1, i);
        alpha[i] = 0;
    }
}

// 가르침
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(str);
    }
    if(K < 5){
        cout << 0 << "\n";
        return 0;
    }

    // a c i n t 필수
    alpha[0] = 1; alpha[2] = 1; alpha[8] = 1;
    alpha[13] = 1; alpha[19] = 1; 
    K -= 5;

    dfs(0, 0);

    cout << CNT << "\n";

    return 0;
}