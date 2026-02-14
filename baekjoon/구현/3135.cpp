#include <iostream>

using namespace std;
int A, B, N, num, result;

// 라디오
int main(){
    cin >> A >> B;
    result = abs(A-B);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        result = min(result, abs(B-num) + 1);
    }

    cout << result << "\n";

    return 0;
}