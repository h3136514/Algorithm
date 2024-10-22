#include <iostream>
#include <string>
#include <stack>

using namespace std;
int sum;
char tmp;
string pipe;
stack<char> st;

// 쇠막대기
int main(){
    cin >> pipe;
    for(int i = 0; i < pipe.size(); i++){
        if(pipe[i] == '('){
            sum++;
            st.push('(');
        }else{
            if(tmp == '('){ // 레이저
                sum--;
                st.pop();
                sum += st.size(); // 잘린 막대기 더함
            }else // 막대기 끝
                st.pop();
            
        }

        tmp = pipe[i];  // 이전 모양 기억 
    }

    cout << sum << "\n";

    return 0;
}

