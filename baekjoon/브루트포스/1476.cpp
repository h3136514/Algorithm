#include <iostream>

using namespace std;
int E, S, M, a, b, c, CNT;

// 날짜 계산
int main(){
    cin >> a >> b >> c;

    while(true){
        CNT++;
        E++;
        S++;
        M++;
        if(E >= 16)
            E = 1;
        if(S >= 29)
            S = 1;
        if(M >= 20)
            M = 1;
        
        if(E == a && S == b && M == c)
            break;
    }

    cout << CNT << "\n";

    return 0;
}