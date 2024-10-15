#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> st;

// 숫자와 "Z"가 공백으로 구분되어 담긴 문자열이 주어지고 문자열에 있는 숫자를 차례대로 더하려고할 때 "Z"가 나오면 바로 전에 더했던 숫자를 뺍니다.
int solution(string s) {
    int answer = 0;
    int plus = 1;
    int tmp = 0;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            tmp = tmp*10 + s[i] -'0';
        }else if(s[i] == '-')
           plus = -1;
         else if(s[i] == 'Z'){
             st.pop();
         }else if(s[i] == ' '){
             st.push(tmp*plus);
             plus =1;
             tmp = 0;
         }
    }
    
    if(s[s.size() -1] != 'Z'){  // 마지막 문자가 삭제가 아니라면 추가
        st.push(tmp*plus);
    }
           
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
           
    return answer;
}