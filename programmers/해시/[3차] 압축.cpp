#include <string>
#include <vector>
#include <map>

using namespace std;
int CNT = 1;
string str;
map<string, int> m;

// LZW 압축
vector<int> solution(string msg) {
    vector<int> answer;
    // 초기 영단어 설정
    for(int i = 0; i < 26; i++){
        str ='A' + i;
        m[str] = CNT++;
    }
    
    str = "";
    for(int i = 0; i < msg.size(); i++){
        str += msg[i];
        if(m.find(str) != m.end()){
            continue;
        }else{
            m[str] =CNT++;  //새로 추가
            str = str.substr(0, str.size()-1); // 기존까지 알고 있는건 결과에 추가
            answer.push_back(m[str]);
            
            str = msg[i]; //다음글자 초기화
        }
    }
    answer.push_back(m[str]); // 마지막 결과에 추가
    
    return answer;
}