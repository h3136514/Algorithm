#include <iostream>
#include <string>

using namespace std;
string str, explore, result;

// 문자열 폭발
int main(){
    cin >> str;
    cin >> explore;

    for(int i = 0; i < str.size(); i++){
        result += str[i];
        if(result.size() < explore.size())  // 복사한 문자열이 폭발 문자열 길이보다 적게 쌍인경우
            continue;
        
        if(result.substr(result.size() - explore.size(), explore.size()) == explore){   // 복사한 문자열 끝부분이 폭발 문자열일 경우
            result.erase(result.size() - explore.size(), explore.size());   // 해당 부분 지우기
        }
    }

    if(result.size() == 0)
        cout << "FRULA\n";
    else
        cout << result << "\n";

    return 0;
}

/* 시간초과 발생

 while(str.find(explore) != -1){
        int n = str.find(explore);
        str.erase(n, explore.size());    // 폭발문자열 제거
    }

*/