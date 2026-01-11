#include <iostream>

using namespace std;
int T, N, M, sum;

//겨울왕국 티켓 예매
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        if(N < 12 || M < 4)
        {
            cout << "-1\n";
            continue;
        }
        sum = 11*M + 4;
        cout << sum << "\n";
    }

    return 0;
}