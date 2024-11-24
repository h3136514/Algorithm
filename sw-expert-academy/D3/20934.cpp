// 방울 마술
#include <iostream>
#include <string>
#include <queue>

using namespace std;
int T, K, O;
string cup;

int main(){
    cin >> T;
    for(int j = 1; j <= T; j++){
        cin >> cup >> K;
        for(int i = 0; i < 3; i++){
            if(cup[i] == 'o')
                O = i;             
        }

        if(K == 0){
            cout << "#" << j << " " << O << "\n";
            continue;
        }
        
        if(K%2 == 0)    // 짝수번 이동
            O = (O == 1) ? 1 : 0;
        else    // 홀수번 이동
            O = (O == 1) ? 0 : 1;
        
        cout << "#" << j << " " << O << "\n";
    }

    return 0;
}