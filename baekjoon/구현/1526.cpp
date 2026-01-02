#include <iostream>
#include <string>

using namespace std;
int N, result;

// 가장 큰 금민수
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        string s = to_string(i);
        int cnt = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '4' || s[j] == '7'){
                cnt++;
                continue;
            }
            break;
        }

        if(cnt == s.size())
            result = i;
    }

    cout << result  << "\n";

    return 0;
}