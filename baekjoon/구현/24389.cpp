#include <iostream>

using namespace std;
int N, idx, bit[32], reverseBit[32], CNT;

// 2의 보수
int main(){
    cin >> N;
    
    // 10진수 => 2진수
    while(N){
        if(N%2 != 0)
            bit[idx] = 1;
        N /= 2;
        idx++;
    }

    // 비트 반전
    for(int i = 0; i < 32; i++){
        reverseBit[i] = (bit[i] == 0) ? 1 : 0;
    }
    reverseBit[0]++;    // +1;

    // 비트올리기
    for(int i = 0; i < 31; i++){
        if(reverseBit[i] == 2){
            reverseBit[i] = 0;
            reverseBit[i+1]++;
        }else
            break;
    }

    // 계산
    for(int i = 0; i < 32; i++){
        if(bit[i] != reverseBit[i])
            CNT++;
    }
    cout << CNT << "\n";

    return 0;
}