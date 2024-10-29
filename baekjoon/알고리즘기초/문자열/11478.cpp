#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int CNT;
string str;
unordered_map<string , int> m;

// 서로 다른 부분 문자열의 개수
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        string target = "";
        for(int j = i; j < str.size(); j++){
            target += str[j];
            if(m.find(target) == m.end()){  // 등록되지 않은 문자열
                m[target]++;
                CNT++;
            }
        }
    }

    cout << CNT << "\n";

    return 0;
}
