#include <iostream>
#include <string>

using namespace std;
int answer;
string s, tmp;

// 팰린드롬 판별
bool isPalindrom(string str){
    int cnt = str.size()/2;
    for(int i = 0; i < cnt; i++){
        if(str[i] != str[str.size()-1-i])
            return false;
    }

    return true;
}

// 팰린드롬 만들기
int main(){
    cin >> s;
    answer = s.size()*2 + 1;
    for(int i = 0; i < s.size(); i++){
        tmp = s.substr(i, s.size()-i);
        if(isPalindrom(tmp)){
            answer = s.size() + i;
            break;
        }
    }

    cout << answer << "\n";

    return 0;
}
