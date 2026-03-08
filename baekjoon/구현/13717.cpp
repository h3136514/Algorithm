#include <iostream>
#include <string>

using namespace std;
int N, K, M, cnt, sum, CNT;
string name, maxName;

// 포켓몬 GO
int main(){
    cin >> N;
    while(N--){
        cin >> name;
        cin >> K >> M;
        cnt = 0;
        while(M >= K){
            M -= K;
            M += 2;
            cnt++;
        }
        
        sum += cnt;
        if(cnt > CNT){
            CNT = cnt;
            maxName = name;
        }
    }

    cout << sum << "\n";
    cout << maxName << "\n";

    return 0;
}