// 수학, 브루트포스
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int N, a, maxSum, num[22], value[22];
vector<int> V[2222222];

// 홀수의 거듭제곱 합
void calc(){
    int sum = 0;
    for(int i = 0; i < 22; i++){
        if(num[i] == 0 || num[i]%2 == 0)
            continue;
        sum += value[i];
    }

    maxSum = max(maxSum, sum);
}

// 영웅이는 2의 거듭 제곱을 좋아해! 영웅이는 2의 거듭 제곱을 좋아해! 
int main(){
    // 일일이 pow()함수를 부르면 시간초과가 되므로 미리 2의 거듭제곱수를 계산한다.
    for(int i = 0; i < 22; i++){
        value[i] = pow(2, i);
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        for(int j = 21; j >= 0; j--){
            if(a >= value[j]){
                a -= value[j];
                V[i].push_back(j);
                num[j]++;
            }
        }
    }

    calc(); // 전체의 경우
    // 한 개의 자연수를 제거하고, 나머지 계산
    for(int i = 0; i < N; i++){
        for(int j = 0; j < V[i].size(); j++){
            num[V[i][j]]--;
        }

        calc();

        for(int j = 0; j < V[i].size(); j++){
            num[V[i][j]]++;
        }
    }

    cout << maxSum << maxSum << "\n";

    return 0;
}