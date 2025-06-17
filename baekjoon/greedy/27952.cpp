#include <iostream>

using namespace std;
long long N, X, weight, A[500001], B[500001];

// 보디빌딩
int main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++){
        cin >> B[i];
        weight += B[i];

        if(A[i] > weight){
            cout << -1 << "\n";

            return 0;
        }
    }

    cout << (weight - A[N-1]) / X << "\n";
    
    return 0;
}