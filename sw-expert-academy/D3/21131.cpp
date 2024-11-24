// 행렬정렬
#include <iostream>

using namespace std;
int T, N, CNT, idx, num[65][65], copyNum[65][65];

// 복사
void copy(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            copyNum[i][j] = num[i][j];
}

// 행렬 정렬 확인
bool check(){
    idx = 0;
    bool result = true;
    int cnt = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(num[i][j] != cnt){   // 행렬이 정렬이 안됨
                result = false;
                idx = max(i, j);  // 정렬이 안됨 열,행 중 가장 큰 위치
            }
            cnt++;
        }
    }

    return result;
}

// 부분행렬을 전치(바꾸기)
void transpose(){
    for(int i = 1; i <= idx; i++){
        for(int j = 1; j <= idx; j++){
            num[i][j] = copyNum[j][i];
        }
    }

}

int main(){
    cin >> T;
    while (T--){
        CNT = 0;
        cin >> N;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                cin >> num[i][j];
        
        while(true){
            if(check())
                break;
            
            copy();
            transpose();
            CNT++;
        }

        cout << CNT << "\n";
    }

    return 0;
}