#include <iostream>
#include <string>

using namespace std;
string S, result, tmp;
bool flag;

// 단어 뒤집기 2
int main(){
    getline(cin, S);    // 공백 포함 입력

    for(int i = 0; i < S.size(); i++){
        if(S[i] == '<'){
            flag = true;
            for(int j = tmp.size() - 1; j >= 0; j--){
                result += tmp[j];
            }
            tmp = "";
            result += S[i];
            continue;
        }
        else if(S[i] == '>'){
            flag = false;
            result += tmp;
            tmp = "";
            result += S[i];
            continue;
        }

        // 태그가 아니고 공백이거나 마지막 문자일때 
        if((S[i] == ' ' && !flag) || i == S.size() - 1){
            if(i == S.size() - 1)
                tmp += S[i];

            for(int j = tmp.size() - 1; j >= 0; j--){
                result += tmp[j];
            }
            if(i != S.size() - 1)
                result += S[i];
            tmp = "";
        }else
            tmp += S[i];
            

    }

    cout << result << "\n";

    return 0;
}