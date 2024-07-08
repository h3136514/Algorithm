#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

//닫힌 괄호의 짝을 바로 확인할 수 있도록 맵 선언(키값을 기준으로 정렬할 필요가 없으므로 unordered_map선언)
unordered_map <char, char> bracketPair = {
    {')', '('}, 
    {']', '['}, 
    {'}', '{'}};

//받은 문자열 기준 괄호짝이 맞는지 확인
bool isValid(string s, int start) {
    stack<char> st;
    int siz = s.length();
    //문자열 순회
    for(int i = 0; i < siz; i++) {
        char c = s[(start+i) % siz]; //회전을 주기위해서 시작점을 계속 변경
         // 닫힌 괄호 인경우
        if(bracketPair.count(c)) {
            //스택이 비었거나 ch와 짝이 맞는 열린괄호가 아닌 경우 false 반환
            if(st.empty() || st.top() != bracketPair[c])
                return false;
            
            st.pop();
        }else
            st.push(c);
    }
    
    return st.empty();   //안비워 있으면 false
}

//대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s에 대해서 왼쪽으로 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수 (시간복잡도 : O(N^2))
int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for(int i = 0; i < n; i++) {
        answer += isValid(s, i);
    }
    return answer;
}

#include <iostream>
int main()
{
    cout << solution("[](){}") << endl; // 3
    cout << solution("}]()[{") << endl; // 2 
    cout << solution("[)(]") << endl;   // 0 
    cout << solution("}}}") << endl;    // 0   
    return 0;
}