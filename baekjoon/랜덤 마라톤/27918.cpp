// 구현, 시뮬레이션
#include <iostream>

using namespace std;
int N, X, Y;
char c;

// 탁구 경기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c;
        if(c=='D')
            X++;
        else
            Y++;
        
        if(abs(X-Y) >= 2)
            break;
    }

    cout << X << ":" << Y <<"\n";

    return 0;
}