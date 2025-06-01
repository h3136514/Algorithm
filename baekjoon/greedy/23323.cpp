#include <iostream>

using namespace std;
int T;
long long N, M, sum;

long long eatCow(long long a, long long b){
    long long day = 0;

    while(a > 0){
        if(a == 1)
            a = 0;
        else
            a /= 2;
        
        day++;
    }

    return day + b;
}

// 황소 다마고치
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;

        cout << eatCow(N, M) << "\n";
    }

    return 0;
}