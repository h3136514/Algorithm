#include <iostream>
#include <string>

using namespace std;
int moCnt, jaCnt;
bool checkM, check;
string s;

void init(){
    moCnt = 0, jaCnt = 0;
    checkM = false;
    check = true;
}

// 모음 유무 확인
bool checkMo(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// 비밀번호 발음하기
int main(){
    while(true){
        cin >> s;
        if(s == "end")
            break;
        init();

        if(checkMo(s[0])){
            checkM = true;
            moCnt++;
        }else
            jaCnt++;
        
        for(int i = 1; i < s.size(); i++){
            if(checkMo(s[i])){
                checkM = true;
                moCnt++;
                jaCnt = 0;
            }else{
                jaCnt++;
                moCnt = 0;
            }

            if(moCnt > 2 || jaCnt > 2){ // 모음이 3개 혹은 자음이 3개 연속
                check = false;
                break;
            }

            if(s[i] == s[i-1] && s[i] != 'e' && s[i] != 'o'){   // 같은 글자가 연속적으로 두번(ee 와 oo는 허용)
                check = false;
                break;
            }
        }

        if(!checkM) // 모음(a,e,i,o,u)이 하나도 포함X
            check = false;
        
        if(check)
            cout << "<" << s << "> is acceptable.\n";
        else
            cout << "<" << s << "> is not acceptable.\n";

    }

    return 0;
}
