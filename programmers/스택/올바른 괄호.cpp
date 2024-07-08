#include<string>
#include <iostream>
#include<stack>

using namespace std;
stack<char> st;

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