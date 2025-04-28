#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int N, num[4000001], CNT = 0, startIdx, endIdx, sum;
vector<int> v;
// 에라토스테네스의 체
void prim(int n){
    num[1] = 1;

    for(int i = 2; i <= sqrt(n); i++){
        if(num[i])
            continue;
        for(int j = i+i; j <= n; j += i){
            if(num[j])
                continue;
            num[j] = 1;
        }
    }
}

// 소수의 연속합
int main(){
    cin >> N;
    prim(N);

    for(int i = 2; i <= N; i++){
        if(num[i])
            continue;

        v.push_back(i);
    }
    v.push_back(0); // 마지막 빈공간 추가(N이 소수 자체 일 수 있으므로) 

    if( N > 1){
        sum += v[0];
        endIdx = 1;

        while(startIdx < endIdx && endIdx < v.size()){
            if(sum > N){
                sum -= v[startIdx++];
            }else if(sum < N){
                sum += v[endIdx++];
            }

            if(sum == N){
                CNT++;
                sum += v[endIdx++];
            }
        }
    }

    cout << CNT << "\n";

    return 0;
}