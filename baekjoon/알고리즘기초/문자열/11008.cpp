// https://www.acmicpc.net/problem/11008
#include <iostream>
#include <string>

using namespace std;
int T, idx, cnt, result;
string s, p;

// 복붙의 달인
int main(){
    cin >> T;
    while(T--){
        cin >> s >> p;

        while(s.find(p, idx) != string::npos){
            idx = s.find(p, idx) + p.size();
            cnt++;
        }
        result = s.size() + cnt - cnt*p.size();
        
        cout << result << "\n";
        idx = 0, cnt = 0;
    }

    return 0;
}