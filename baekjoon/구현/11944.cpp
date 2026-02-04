#include <iostream>
#include <string>

using namespace std;
int N, NN, M, targetCnt, cnt;
string s;

// NN
int main(){
    cin >> s >> M;
    N = s.size();
    NN = N*stoi(s);
    targetCnt = (NN < M) ? NN : M;
    
    while(cnt < targetCnt){
        cout << s[cnt%N];
        cnt++;
    }
    cout << "\n";

    return 0;
}