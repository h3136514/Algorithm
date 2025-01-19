// 그리디
#include <iostream>

using namespace std;
int N, K, X[100001], num, cnt;

// 오리와 박수치는 춘배
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    cnt = 1;
    num = X[0] + K;
    for(int i = 1; i < N; i++){
        if(num >= X[i])
            continue;

        cnt++;
        num = X[i] + K;
    }

    cout << cnt << "\n";

    return 0;
}