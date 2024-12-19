// 수학, 조합론
#include <iostream>

using namespace std;
int T, N, M, K, D, Y, Z, A, B, sum, result;

// 야구 시즌 
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M >> K >> D;
        result = -1;

        Y = N * M * (M-1)/2;    // 지역리그 * 팀 조합수(같은 리그에서의 가능한 경기 수)
        Z = N * (N-1)/2*M*M;    // 다른 지역리그와의 조합수*경기수(각팀원을 곱함)
        B = 1;
        while(true){
            A = B*K;
            int e = Z*B;
            int i = Y*A;
    
            sum = i + e;
            if(sum > D)
                break;
            else
                result = sum;

            B++;
        }

        cout << result << "\n";
    }

    return 0;
}