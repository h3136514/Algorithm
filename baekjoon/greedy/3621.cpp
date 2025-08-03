#include <iostream>

using namespace std;
int N, D, a, sum, num[100001];

// 족보
int main(){
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> a;
        num[a]++;
    }

    for(int i = 0; i <= N; i++){
        if(num[i] > D){
            sum += (num[i] - 2) /(D -1);
        }
    }

    cout << sum << "\n";

    return 0;
}