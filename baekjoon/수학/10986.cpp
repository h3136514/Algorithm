//누적합, 수학
#include <iostream>

using namespace std;
int N, M, tmp;
long long sum, result, v[1001];

// 나머지 합
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){ // 구간까지의 누적합
        cin >> tmp;
        sum += tmp;
        v[sum % M]++;

        if(sum % M == 0)
            result++;
    }

    for(int i = 0; i <= M; i++){     // nC2의 느낌 (N개중 2개를 고름 :  (i, j) 쌍의 개수 이므로)
        result += v[i] * (v[i]-1)/2;
    }

    cout << result << "\n";

    return 0;
}
