#include <iostream>
#include <string>

using namespace std;
int T, answer;
string s;

void init(){
    answer = 2;
}

void cal(int startIdx, int endIdx, int an){
    if(startIdx > endIdx || an >= 2)
        return;

   while(startIdx <= endIdx){
        if(s[startIdx] == s[endIdx]){
            startIdx++;
            endIdx--;
        }else{
            an++;
            cal(startIdx+1, endIdx, an);
            cal(startIdx, endIdx-1, an);
        }

        if(an >= 2)
            break;
    }
    answer = min(answer, an);
}

// 회문
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        init();

        cal(0, s.size() - 1, 0);
        
        cout << answer << "\n";
    }

    return 0;
}