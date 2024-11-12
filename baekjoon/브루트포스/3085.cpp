#include <iostream>
#include <algorithm>    //swap()함수 사용
#include <string>

using namespace std;
int N, CNT, tmp;
string candy[51];

// 현재 사탕 최대개수 반환
int numCandy(){
    int result = 1;
    // 행 확인
    for(int i = 0; i < N; i++){
        int cnt = 1;
        for(int j = 0; j < N - 1; j++){
            if(candy[i][j] == candy[i][j+1])
                cnt++;
            else{
                result = max(result, cnt);
                cnt = 1;
            }

            result = max(result, cnt);
        }
    }
    // 열 확인
    for(int i = 0; i < N; i++){
        int cnt = 1;
        for(int j = 0; j < N - 1; j++){
            if(candy[j][i] == candy[j+1][i])
                cnt++;
            else{
                result = max(result, cnt);
                cnt = 1;
            }

            result = max(result, cnt);
        }
    }

    return result;
}

// 사탕 게임
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> candy[i];
    }

    CNT = numCandy();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            // 오른쪽하고 바꾸기(행)
            swap(candy[i][j], candy[i][j+1]);
            CNT = max(CNT, numCandy());
            swap(candy[i][j], candy[i][j+1]);

            // 아래하고 바꾸기(열)
            swap(candy[j][i], candy[j+1][i]);
            CNT = max(CNT, numCandy());
            swap(candy[j][i], candy[j+1][i]);
        }
    }

    cout << CNT << "\n";

    return 0;
}