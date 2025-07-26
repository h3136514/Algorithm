#include <iostream>
#include <cmath>
#include <stack>
#include <string>

using namespace std;
int N, CNT, dept;
string s;
stack<char> st;

// 원숭이 매달기
int main(){
    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++){
        getline(cin, s);
        if(s.length() == 0)
            dept = 1;
        else{
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '[')
                    st.push('[');
                else
                    st.pop();

                int si = st.size();
                dept = max(dept, si);   //  트리의 최대 깊이
            }
            dept = pow(2, dept);
        }

        cout << dept << "\n";
        s.clear();
        dept = 0;
    }

    return 0;
}