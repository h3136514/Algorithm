//구현, 그래프 탐색
#include <iostream>

using namespace std;
int N, M, CNT;
char wood[51][51];

// 바닥 장식
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> wood[i][j];
    
    // 가로 나무 판자 확인
    for(int i = 0; i < N; i++){
        char tmp = '|';
        for(int j = 0; j < M; j++){
            if(tmp == '-' && wood[i][j] == '-')
                continue;
            
            if(wood[i][j] == '-'){
                CNT++;
                tmp = '-';
            }else
                tmp = '|';
        }
    }

    // 세로 나무 판자 확인
    for(int i = 0; i < M; i++){
        char tmp = '-';
        for(int j = 0; j < N; j++){
            if(tmp == '|' && wood[j][i] == '|')
                continue;
            
            if(wood[j][i] == '|'){
                CNT++;
                tmp = '|';
            }else
                tmp = '-';
        }
    }
       
    cout << CNT << "\n";

    return 0;
}