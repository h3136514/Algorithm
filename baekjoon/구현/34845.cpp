#include <iostream>

using namespace std;
int N, X, A, sum, cnt;

// 강의평
int main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> A;
        sum += A;
    }

    while(true){
        if((sum/(N+cnt)) >= X){
            break;
        }
        cnt++;
        sum += 100;
    }

    cout << cnt << "\n";

    return 0;
}