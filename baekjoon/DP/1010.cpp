#include <iostream>

using namespace std;
int T, N, M;
long long C[31][31];

// 다리 놓기
int main(){
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= 30; i++){
        C[i][0] = 1;
        for(int j = 1; j <= 30; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    cin >> T;
    while(T--){
        cin >> N >> M;
        cout << C[M][N] << "\n";
    }

    return 0;
}