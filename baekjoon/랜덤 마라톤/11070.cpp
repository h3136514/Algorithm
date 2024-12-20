// 구현, 수학
#include <iostream>

#define INF 987654321
using namespace std;
double minV = INF, maxV = -1, plusV[1001], minusV[1001];
int T, N, M, a, b, p, q;

// 초기화
void init(){
    minV = INF, maxV = -1;
    for(int i = 1; i <= N; i++){
        plusV[i] = 0;
        minusV[i] = 0;
    }
}

// 피타고라스 기댓값
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 1; i <= M; i++){
            cin >> a >> b >> p >> q;
            plusV[a] += p;
            plusV[b] += q;

            minusV[a] += q;
            minusV[b] += p;
        }

        // 점수 계산
        for(int i = 1; i <= N; i++){
            double sum = 0;
            if(plusV[i] != 0)   // 0을 나누면 안되므로
                sum = plusV[i]*plusV[i]/(plusV[i]*plusV[i] + minusV[i]*minusV[i]);
    
            minV = min(minV, sum*1000);
            maxV = max(maxV, sum*1000);
        }
     
        cout << (int)(maxV) << "\n";
        cout << (int)(minV) << "\n";

        init();
    }

    return 0;
}