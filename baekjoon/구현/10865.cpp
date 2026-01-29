#include <iostream>

using namespace std;
int N, M, A, B, num[100001];

// 친구 친구
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        num[A]++, num[B]++;
    }

    for(int i = 1; i <= N; i++){
        cout << num[i] << "\n";
    }

    return 0;
}