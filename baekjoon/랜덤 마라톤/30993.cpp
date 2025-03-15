// 수학, 조합론
#include <iostream>

using namespace std;
int N, A, B, C;
long long result;
// 조합 계산
long long cal(int a, int b){
    if(a <= b)
        return 1;

    long long top = 1, down = 1;

    for(int i = 0; i < b; i++){
        top *= (a-i);
        down *= i+1;
    }

    return top/down;
}

// 자동차 주차
int main(){
    cin >> N >> A >> B >> C;
   
    result = cal(N, A) * cal(N-A, B) * cal(N-A-B, C);
    cout << result << "\n";

    return 0;
}