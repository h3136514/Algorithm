#include <iostream>
#include <string>

#define MAX 9999999999
using namespace std;
int K, num[10], visitied[10];
long long minNum = MAX, maxNum;
string minNumStr, maxNumStr;
char c[9];

// 백트래킹
void dfs(int cnt){
    if(cnt == K+1){
        string s = "";
        for(int i = 0; i < K+1; i++){
            s += num[i] + '0';
        }

        long long a = stoll(s); // 문자열 => long long
        if(minNum > a){
            minNum = a;
            minNumStr = s;
        }
        if(maxNum < a){
            maxNum = a;
            maxNumStr = s;
        }

        return;
    }

    for(int i = 0; i < 10; i++){
        if(!visitied[i]){
            if((c[cnt-1] == '<' && num[cnt-1] < i) || (c[cnt-1] == '>' && num[cnt-1] > i)){
                visitied[i] = 1;
                num[cnt] = i;
                dfs(cnt+1);
                visitied[i] = 0;
            }
        }
    }
}

// 부등호
int main(){
    cin >> K;
    for(int i = 0; i < K; i++)
        cin >> c[i];
    
    for(int i = 0; i < 10; i++){
        visitied[i] = 1;
        num[0] = i;
        dfs(1);
        visitied[i] = 0;
    }

    cout << maxNumStr << "\n";
    cout << minNumStr << "\n";

    return 0;
}