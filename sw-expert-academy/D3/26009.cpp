// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZv9opVqDDXHBIQE&categoryId=AZv9opVqDDXHBIQE&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
#include <iostream>

#define MOD 998244353
using namespace std;
int T;

long long cal(long long target){
    return (target*(target+1)/2) % MOD;
}

// 곱의 합
int main(){
    cin >> T;

    while(T--){
        long long A, B, C;
        cin >> A >> B >> C;

        cout << ((cal(A)*cal(B))%MOD)*cal(C)%MOD << "\n";
    }

    return 0;
}