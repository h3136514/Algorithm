#include <iostream>
#include <vector>

using namespace std;
int N, C, W, maxL;
long long answer;
vector<int> v;

// 나무꾼 이다솜
int main(){
    cin >> N >> C >> W;

    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        maxL = max(maxL, v[i]); // 나무 길이 최댓값
    }

    for(int i = 1; i <= maxL; i++){
        long long sum = 0;
        for(int j = 0; j < v.size(); j++){
            if(i == v[j])
                sum += i * W;
            else if(i < v[j]){
                // 각 나무에 대한 수익 계산
                int t =(v[j] % i == 0) ? -1 : 0; //  자르는 횟수의 정확히 계산
                int plus = (i * W) * (v[j] / i); // 판매 수익 추가
                int minus = (v[j] / i + t) * C; // 자르는 비용 차감

                if(plus > minus){
                    sum -= minus;
                    sum += plus;
                }
            }
        }

        answer = max(answer, sum);
    }

    cout << answer << "\n";

    return 0;
}