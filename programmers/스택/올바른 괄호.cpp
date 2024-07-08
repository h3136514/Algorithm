#include<string>
#include<stack>

using namespace std;
stack<char> st;

// 괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. (시간복잡도 : O(N))
bool solution(string s)
{
    bool answer = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')'){
            if(st.empty())
                return false;
            
            st.pop();
        }
    }
    
    // 아직 괄호가 남아있으면
    if(!st.empty())
        answer = false;
    
    return answer;
}

#include <iostream>
int main()
{
    //true를 출력하면 1 이고, false를 출력하면 0
    
    cout << solution("(())()") << endl;  // 1
    cout << solution("((())()") << endl; // 0 

    return 0;
}