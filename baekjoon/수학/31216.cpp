#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int T, N, num[318138];
vector<int> v;

// 에라토스테네스의 체 (소수 확인)
void primeNumber(int n) {
    num[1] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (num[i])
            continue;
        for (int j = i + i; j <= n; j += i) {
            if (num[j])
                continue;
            num[j] = 1;
        }
    }
}

// 슈퍼 소수
int main(){
    primeNumber(318137);
    int cnt = 1;
    for(int i = 2; i <= 318137; i++){
        if(!num[i]){
            if(!num[cnt])
                v.push_back(i);
            cnt++;
        }
    }

    cin >> T;
    while(T--){
        cin >> N;
        cout << v[N-1] << "\n";
    }

    return 0;
}