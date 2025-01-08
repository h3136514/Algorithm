// 수학, 사칙연산
#include <iostream>

using namespace std;
int T, N, M;

// 남욱이의 닭장
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = M; i >= 0; i--){
            if(i*2 + M-i == N){
                cout << M-i << " " << i << "\n";
                break;
            }
        }
    }
    return 0;
}
