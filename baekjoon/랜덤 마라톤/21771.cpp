// 구현
#include <iostream>

using namespace std;
int R, C, Rg, Cg, Rp, Cp, CNT;
char c;

// 가희야 거기서 자는 거 아니야
int main(){
    cin >> R >> C;
    cin >> Rg >> Cg >> Rp >> Cp;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> c;
            if(c =='P')
                CNT++;
        }
    }

    if(CNT == Rp*Cp)
        cout << "0\n";
    else
        cout << "1\n";

    return 0;
}