#include <iostream>

using namespace std;
int N, S[200001], startIdx, endIdx, cnt = 1, num[10];

// 숫자 갯수 세기
int getCnt(){
    int fruit = 0;
    for(int i = 1; i < 10; i++){
        if(num[i])
            fruit++;
    }

    return fruit;
}

// 과일 탕후루
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    num[S[endIdx]]++;
    while(startIdx < N){
        while(endIdx < N){
            endIdx++;
            if(endIdx == N)
                break;
            
            num[S[endIdx]]++;
            if(getCnt() > 2){
                num[S[endIdx--]]--;
                cnt = max(cnt, endIdx - startIdx +1);
                break;
            }

            cnt = max(cnt, endIdx - startIdx +1);
        }

        num[S[startIdx++]]--;
    }

    cout << cnt << "\n";

    return 0;
}