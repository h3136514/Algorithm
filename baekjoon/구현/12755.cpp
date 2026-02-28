#include <iostream>
#include <string>

using namespace std;
int N, cnt = 1, idx = 0;
string s;

// 수면 장
int main(){
    cin >> N;

    while(true){
        s = to_string(cnt);
        cnt++;
        if(idx + s.size() < N){
            idx += s.size();
            continue;
        }
        N -= idx;
        cout << s[N-1] << "\n";   
        break;
    }

    return 0;
}