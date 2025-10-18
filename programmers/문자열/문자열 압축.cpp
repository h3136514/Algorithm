//https://school.programmers.co.kr/learn/courses/30/lessons/60057?language=java1&gad_source=1&gad_campaignid=22799790467&gbraid=0AAAAAC_c4nDwyqzZcB4WSuHySDy6hD2fh&gclid=CjwKCAjw0sfHBhB6EiwAQtv5qVul_mz_0_2_UcY2eKW3g4SdqoibWJyiAOQBUXumlYTA6pUhq4oRlRoC79YQAvD_BwE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer;

void lenStr(int k, string s){
    string ago = s.substr(0, k);    //0부터 k개
    string tmp = "";
    int cnt = 1;
    
    for(int i = k; i < s.size(); i += k){
        if(ago == s.substr(i, k)) 
            cnt++;
        else{
            if(cnt > 1){
                tmp += to_string(cnt);
            }
            tmp += ago;
            ago = s.substr(i, k);
            cnt = 1;
         }
    }
    
    if(cnt > 1){
        tmp += to_string(cnt);
    }
    tmp += ago;
    int sSize = tmp.size();
    
    answer = min(answer, sSize);
}


int solution(string s) {
    answer = s.size();
    //  1~절반 단위로 문자열을 잘라 압축 
    for(int i = 1; i <= s.size()/2; i++){
        lenStr(i, s);
    }
    
    return answer;
}