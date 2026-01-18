#include <iostream>
#include <string>

using namespace std;
int N, cnt;
string s;

// 내 선물을 받아줘 2
int main(){
    cin >> N;
    cin >> s;
    for(int i = 0; i < N-1; i++){
        if(s[i] == 'E' && s[i + 1] == 'W')
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}