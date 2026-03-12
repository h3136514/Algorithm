#include <iostream>

using namespace std;
int N, M, result;

// 스네이크
int main(){
    cin >> N >> M;
    result = (N*M)%2 == 0 ?  N*M : N*M-1;

    cout << result << "\n";
    return 0;
}