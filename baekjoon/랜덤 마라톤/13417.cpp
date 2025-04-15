// 문자열, 그리디
#include <iostream>
#include <string>

using namespace std;
int T, N;
string s, result;

// 카드 문자열
int main(){
    cin >> T;
    while(T--){
        result = "";
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> s;
            if(s > result)
                result += s;
            else
                result = s + result;
        }

        cout << result << "\n";
    }

    return 0;
}