#include <iostream>
#include <string>

using namespace std;
int T, N;

// 초콜릿과 11과 팰린드롬
int main(){
    cin >> T;
    while (T--){
        cin >> N;
        if(N == 1)
            cout << "0\n";
        else{   // 11의 배수 판정법으로 인해 홀수 자리와 짝수 자리의 합의 차가 0(가운데에 2를 계속 집어넣으면 홀수 자리와 짝수 자리의 합의 차가 0)
            cout << "1";
            for(int i = 0; i < N-2; i++)
                cout << "2";
            cout << "1\n";
        }
    
    }

    return 0;
}