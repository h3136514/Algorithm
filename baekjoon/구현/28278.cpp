#include <iostream>
#include <stack>

using namespace std;
int N, num, X, answer;
stack<int> st;

// 스택 2
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == 1){
            cin >> X;
            st.push(X);
            continue;
        }else if(num == 2){
            answer = -1;
            if(!st.empty()){
                answer = st.top();
                st.pop();
            }
        }else if(num == 3)
            answer = st.size();
        else if(num == 4)
            answer = (st.empty()) ? 1 : 0;
        else
            answer = (st.empty()) ? -1 : st.top();

        cout << answer << "\n";
    }

    return 0;
}