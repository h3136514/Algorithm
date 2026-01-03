#include <iostream>

using namespace std;
int K, N, M;

// 과자
int main(){
    cin >> K >> N >> M;
    if(K*N <= M)
        cout <<"0\n";
    else{
        cout << K*N - M << "\n";
    }

    return 0;
}