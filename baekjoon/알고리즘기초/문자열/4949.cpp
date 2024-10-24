#include <iostream>
#include <string>
#include <stack>

using namespace std;
string str;
stack<char> st; //소괄호"(", 대괄호"[" 저장 스택

void init(){
    while(!st.empty())
        st.pop(); 
}

// 균형잡힌 세상
int main(){
    while(true){
        getline(cin, str, '.'); //공백 포함 및 종결문자 지정

        // 종료조건
        if(str.size() == 1)
            break;

        bool balance = true;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '.')
                break;

            if(str[i] == '(')
                st.push('(');
            if(str[i] == '[')
                st.push('[');
            
            if(str[i] == ')' || str[i] == ']'){
                if(st.empty()){
                    balance = false;
                    break;
                }
                if(str[i] == ')' && st.top() =='(' || str[i] == ']' && st.top() =='[')
                    st.pop();
                else{
                    balance = false;
                    break;
                } 
            }
        }

        if(!st.empty())
            balance = false;
        
        if(balance)
            cout << "yes\n";
        else
            cout << "no\n";

        init();
        
    }

    return 0;
}