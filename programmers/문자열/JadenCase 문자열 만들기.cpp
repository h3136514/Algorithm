// 주의: 공백문자가 연속해서 나올 수 있음
#include <string>
#include <vector>

using namespace std;
string answer = "";
vector<string> v;

// 알파벳 소문자 확인
bool checkBigAlpa(char c){
    int num = int(c);
    
    if(65 <= num && num <= 90)
        return true;
    
    return false;
}

// 알파벳 대문자 확인
bool checkSmallAlpa(char c){
    int num = int(c);
    
    if(97 <= num && num <= 122)
        return true;
    
    return false;
}

// JadenCase 문자열로 변경
string addStr(string s){
    string tmp = "";
    if(checkSmallAlpa(s[0])){    // 맨처음문자가 소문자인지
        s[0] -= 32; 
    }
    tmp += s[0];

    for(int i = 1; i < s.size(); i++){
        if(checkBigAlpa(s[i]))
            s[i] += 32; 
        tmp += s[i];    
    }
    
    return tmp;
}


string solution(string s) {
    string word = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            if(word.empty()){
                answer += " ";  // 공백 문자가 연속으로 가능함
                continue;
            }
         answer += addStr(word);
         answer += " ";
        
         word = "";
        }else
            word += s[i];
        
    }
    // 마지막 단어도 추가
    if(!word.empty())
        answer += addStr(word);
    
    return answer;
}

/*
// 다른 풀이 더 간단한
string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}

*/