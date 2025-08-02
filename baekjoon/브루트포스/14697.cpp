#include <iostream>
#include <vector>

using namespace std;
int N, A, B, C, answer;

// 방 배정하기
int main(){
    cin >> A >> B >> C >> N;
    
    for(int i = 0; i <= N/A + 1; i++){
        for(int j = 0; j <= N/B + 1; j++){
            for(int k = 0; k <= N/C + 1; k++){
                if(A*i + B*j + C*k == N)
                    answer = 1;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}