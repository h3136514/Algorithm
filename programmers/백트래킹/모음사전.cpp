#include <string>
#include <vector>

using namespace std;
int cnt = -1;
int answer;
string target = "";
string alp ="AEIOU";

void dfs(string word) {
    cnt++;  // dfs 수행할 때마다 cnt++ 
    if(word == target){
        answer = cnt;
        return;
    }
    if(word.length() >= 5)
        return;
    
    for(int i = 0; i < 5; i++) {
        dfs(word + alp[i]);
    }
    
}

// 사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다. 단어 하나가 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 반환
int solution(string word) {
    target = word;
    dfs("");
    
    return answer;
}



#include <iostream>

int main() {
    cout << solution("AAAAE") << endl;  // 출력값 : 6
}