#include <iostream>

using namespace std;
int N, num[1001], maxCnt;

// 최장 스트릭
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(num[i] > 0){
            cnt++;
            maxCnt = max(maxCnt, cnt);
        }else
            cnt = 0;
    }

    cout << maxCnt << "\n";

    return 0;
}