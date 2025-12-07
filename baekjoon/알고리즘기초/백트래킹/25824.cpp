#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;
int num[12][12], result = INF;

void dfs(int agoIdx, int idx, int agoCnt, int cnt, int sum){
    if(cnt == 6){
        result = min(result, sum);
        return;
    }

    int value = num[agoIdx][idx];
    if(agoCnt == cnt){
        dfs(idx, (cnt+1)*2, cnt, cnt + 1, sum + value);
        dfs(idx, (cnt+1)*2+1, cnt, cnt + 1, sum + value);
    }else{
        if(idx % 2 == 0)
            dfs(idx, idx+1, cnt, cnt, sum + value);
        else
            dfs(idx, idx-1, cnt, cnt, sum + value);
    }
}

// 빠른 오름차순 메시지 전달
int main(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> num[i][j];
        }  
    }

    dfs(1, 0, 0, 0, 0);
    dfs(0, 1, 0, 0, 0);

    cout << result << "\n";
    return 0;
}