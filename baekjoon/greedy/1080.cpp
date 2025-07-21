#include <iostream>

using namespace std;
int N, M, ans; 
char A[51][51], B[51][51];

// 행렬
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> A[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> B[i][j];

    for(int i = 0; i < N -2; i++){
        for(int j = 0; j < M -2; j++){
            if(A[i][j] != B[i][j]){
                 for(int l = i; l <= i + 2; l++)
                    for(int k = j; k <= j + 2; k++)
                        A[l][k] = (A[l][k] == '0') ? '1' : '0';
                
                ans++;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(A[i][j] != B[i][j]){
                ans = -1;
                break;
            }
        }
        if(ans == -1)
            break;
    }
    
    cout << ans << "\n";

    return 0;
}