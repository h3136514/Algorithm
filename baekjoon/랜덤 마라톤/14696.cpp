// 구현
#include <iostream>

using namespace std;
int N, ACNT, BCNT, num, A[5], B[5];

// 초기화
void init(){
    for(int i = 1; i <= 4; i++){
        A[i] = 0;
        B[i] = 0;
    }
}

// 딱지놀이
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ACNT;
        for(int j = 0; j < ACNT; j++){
            cin >> num;
            A[num]++;
        }

        cin >> BCNT;
        for(int j = 0; j < BCNT; j++){
            cin >> num;
            B[num]++;
        }

        char winner = 'D';
        for(int j = 4; j > 0; j--){
            if(A[j] == B[j])
                continue;
            
            if(A[j] > B[j])
                winner = 'A';
            else
                winner = 'B';
            
            break;
        }

        cout << winner << "\n";

        init();
    }

    return 0;
}