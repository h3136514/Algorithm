#include <iostream>
#include <string>

using namespace std;
int N, M, ans, CNT;
string S;

// IOIOI
int main(){
    cin >> N;
    cin >> M;
    cin >> S;

    for(int i = 0; i < M; i++){
        if(S[i] == 'O') // I로 시작
            continue;
       
        CNT = 0; // OI의 개수
        while (S[i+1] == 'O' && S[i+2] == 'I'){
            CNT++;

            if(CNT == N){
                ans++;
                CNT--;
            }
            i += 2; // 두칸 넘어가기
        }       
    }

    cout << ans << "\n";

    return 0;
}