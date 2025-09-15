#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
int r, c, k, tmpR, tmpC, A[101][101], tmp[101][101], maxR = 3, maxC= 3, T;
priority_queue<pair<int, int>> q;
unordered_map<int, int> m;

// 수 확인
bool check(){
    return A[r][c] == k;
}
// 초기화
void init(){
    while(!q.empty()){
        q.pop();
    }

    m.clear();
}
// 배열 복사
void copyArray(){
    int N = max(maxR, maxC);
     for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            A[i][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
}

// 이차원 배열과 연산
int main(){
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> A[i][j];
        }
    }

    while(T <= 100){
        if(check())
            break;
        
        T++;
        if(maxR >= maxC){
            tmpC = maxC;
            maxC = 0;
            for(int i = 1; i <= maxR; i++){
                for(int j = 1; j <= tmpC; j++){
                    if( A[i][j] == 0)
                        continue;

                    m[A[i][j]]++;
                    A[i][j] = 0;
                }

                for(auto num : m){
                    q.push({-num.second, -num.first});
                }     

                for(int j = 1; j + 2 <= 100; j += 2){
                    if(q.empty())
                        break;

                    maxC = max(maxC, j+1);
                    tmp[i][j] = -q.top().second;
                    tmp[i][j+1] = -q.top().first;
                    q.pop();
                }

                init();
            }

        }else{
            tmpR = maxR;
            maxR = 0;
            for(int i = 1; i <= maxC; i++){
                for(int j = 1; j <= tmpR; j++){
                    if( A[j][i] == 0)
                        continue;

                    m[A[j][i]]++;
                    A[j][i] = 0;
                }

                for(auto num : m){
                    q.push({-num.second, -num.first});
                }     

                for(int j = 1; j + 2 <= 100; j += 2){
                    if(q.empty())
                        break;

                    maxR = max(maxR, j+1);
                    tmp[j][i] = -q.top().second;
                    tmp[j+1][i] = -q.top().first;
                    q.pop();
                }

                init();
            }
        }

        copyArray();
    }

    if(T > 100)
        T = -1;

    cout << T << "\n";

    return 0;
}