// 브루트포스
#include <iostream>

using namespace std;
int sum, num[9], visitied[9];

// 백트래킹
void dfs(int idx, int cnt, int s){
    if(cnt == 2){
        if(s == 100){
            for(int i = 0; i < 9; i++){
                if(!visitied[i])
                    cout << num[i] << "\n";
            }
        }
        return;
    }

    for(int i = idx; i < 9; i++){
        visitied[i] = 1;
        dfs(i+1, cnt+1, s-num[i]);
        visitied[i] = 0;
    }
}

// 백설 공주와 일곱 난쟁이
int main(){
    for(int i = 0; i < 9; i++){
        cin >> num[i];
        sum += num[i];
    } 

    dfs(0, 0, sum);

    return 0;
}