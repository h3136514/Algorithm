#include<iostream>
#include<string>
#include<stack>

using namespace std;
string S;
int sum, rCnt, cnt = 1;
stack<char> st;

// 안정적인 문자열
int main(){
    while(true){
        getline(cin, S);
        if(S.find("-") != string :: npos)
            break;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '{')
                st.push('{');
            else if(S[i] == '}'){
                if(st.empty())
                    rCnt++;
                else
                    st.pop();
            }
        }

        sum += (rCnt/2 + rCnt%2) ;
        sum += (st.size()/2 + st.size()%2) ;

        cout << cnt++ << ". " << sum << "\n";

        sum = 0, rCnt = 0;
        while(!st.empty())
            st.pop();
    }
    return 0;
}