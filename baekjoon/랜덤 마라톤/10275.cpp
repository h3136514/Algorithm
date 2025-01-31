// 수학, 구현
#include <iostream>
#include <cmath>    // 제곱 pow()함수를 사용하기 위해

using namespace std;
long long T, N, a, b, num, result;

// 골드 러시 
int main(){
    cin >> T;
    while ((T--)){
        cin >> N >> a >> b;
        long long minNum = min(a, b);

        for(int i = N; i >= 0; i--){
            num = pow(2, i);
            if(minNum % num == 0){
                result =  N - i;
                break;
            }
        }

        cout << result << "\n";
    }

    return 0;
}