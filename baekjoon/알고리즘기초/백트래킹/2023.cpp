#include <iostream>
#include <cmath>

using namespace std;
int N;

// 소수 체크
bool isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }

    return true;
}

// 백트래킹(각 n자리의 수가 소수가 맞는지 조합을 찾기)
void dfs(int cnt, int num){
    if(cnt == N){
        cout << num << "\n";
        return;
    }

    for(int i = 1; i <= 9; i++){
        if(isPrime(num*10 + i))
            dfs(cnt+1, num*10 + i);
    }
}

// 신기한 소수
int main(){
    cin >> N;

    dfs(1, 2);
    dfs(1, 3);
    dfs(1, 5);
    dfs(1, 7);

    return 0;
}