#include <iostream>
#include <string>

using namespace std;
int cnt;
string S;

int main() {
    cin >> S;
    
    for(int i = 1; i < S.size(); i++)
        if(S[i] != S[i-1] && S[i] != S[0])
            cnt++;

    cout << cnt << endl;

    return 0;
}