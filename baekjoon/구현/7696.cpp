#include <iostream>

using namespace std;
int a, num[10], answer, CNT;

void init(){
    for(int i = 0; i < 10; i++)
        num[i] = 0;
}

void dfs(int cnt, int value, int size){
    if(cnt == size){
        CNT++;
        if(CNT == a){
            answer = value;
        }

        return;
    }

    int idx;
    if(cnt == 0)
        idx = 1;
    else
        idx = 0;

    for(int i = idx; i < 10; i++){
        if(!num[i]){
            num[i] = 1;
            dfs(cnt+1, value*10 + i, size);
            num[i] = 0;
        }

        if(answer)
            break;
    }

}

// 반복하지 않는 수
int main(){
    while (true){
        cin >> a;
        if(a == 0)
            break;

        for(int i = 1; i <= 10; i++){   // 10자리 수 까지
            init();
            dfs(0, 0, i);
            if(answer)
                break;
        }
        
        cout << answer << "\n";
        CNT = 0;
        answer = 0;
    }

    return 0;
}