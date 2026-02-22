#include <iostream>

using namespace std;
int N, K, num[32][32];

// 파스칼의 삼각형
int main(){
    num[1][1] = 1;
    num[2][1] = 1, num[2][2] = 1;
    
    cin >> N >> K;
    for(int i = 3; i <= N; i++){
        for(int j = 1; j <= i; j++){
           num[i][j] = num[i-1][j] + num[i-1][j-1];
        }
    }

    cout << num[N][K] << "\n";

    return 0;
}