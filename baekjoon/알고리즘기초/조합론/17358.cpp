#include <iostream>

#define MAX 1000000007
using namespace std;
int N;
long long result = 1;

// 복불복으로 지구 멸망
int main(){
    cin >> N;
    while(N){
        result *= (N-1);
        result %= MAX;

        N -= 2; // n개의 포트중 2개씩 사용할 없게 되므로 다음번에 고를 수 있는건 n-2개
    }
    
    cout << result << "\n";

    return 0;
}