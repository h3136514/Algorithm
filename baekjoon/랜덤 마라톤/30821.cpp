// 수학, 조합론
#include <iostream>

using namespace std;
int N;
long long result = 1;

// 별자리가 될 수 있다면
int main(){
    cin >> N;
    for(int i = N; i > N-5; i--)
        result *= i;
    
    cout << result/120 << "\n";

    return 0;
}