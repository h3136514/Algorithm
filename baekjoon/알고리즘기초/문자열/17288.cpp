#include <iostream>
#include <string>

using namespace std;
int result;
string st, tmp;

// 연속된 세 숫자인지 확인
void check(char c){
    int a = c -'0';
    int b = tmp[tmp.size()-1] -'0';
    if(a  != b +1){
        if(tmp.size() == 3)
            result++;

        tmp  = c;
    }else
        tmp += c;

    return;
}

// 3개만!
int main(){
    cin >> st;

    tmp = st[0];

    for(int i = 1; i < st.size(); i++){
        if(tmp.empty()){
            tmp += st[i];
            continue;
        }

        check(st[i]);
    }

    check('0');
    cout << result << "\n";

    return 0;
}