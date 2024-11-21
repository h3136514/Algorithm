// 높은 곳으로
#include <iostream>

using namespace std;
int T, N, P, CNT;
bool check;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> P;
        CNT = 0;
        check = false;
        for(int i = 1; i <= N; i++){
            CNT += i;
            if(CNT == P)
                check = true;
        }
        if(CNT == P || check)   // 최대높이가 폭탄이거나 중간에 폭탄이 있었으면 -1(1층을 안감)
            CNT--;

        cout << CNT << "\n";
    }

    return 0;
}