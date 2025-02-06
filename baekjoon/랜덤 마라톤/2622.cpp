// 수학
#include <iostream>

using namespace std;
int N, CNT;

// 삼각형만들기
int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j++){
            int k = N-i-j;  // 가장 큰 변
            if(j>k)
                break;
            if(j+i > k) // 두변의 합 > 가장 큰 변
                CNT++;
        }
    }

    cout << CNT << "\n";

    return 0;
}