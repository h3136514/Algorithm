#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
string S;
int N;
long long result = 0;
vector<int> v, alpha = {'A', 'B'};  // 모음, 자음 상징
map<char, bool> m;

bool check(string s){
    bool impos = true;
    int ja = 0, mo = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '_'){
            ja = 0, mo = 0;
            continue;
        }

        if(m.find(s[i]) != m.end()){
            mo++;
            ja = 0;
        }else{
            ja++;
            mo = 0;
        }

        if(ja >= 3 || mo >= 3){
            impos = false;
            break;
        }
    }

    return impos;
}

void backtrack(int idx, long long sum, string s, bool checkL){
    if(idx == N){
        if(checkL){
            result += sum;
        }
        return;
    }

    for(int i = 0; i < 2; i++){
        s[v[idx]] = alpha[i];

        if(check(s)){
            long long isum;
            if(i == 0){ // 모음
                isum = 5;
                backtrack(idx + 1, sum * isum, s, checkL);
            }else{  // 자음
                isum = 21;
                if(!checkL){
                    backtrack(idx + 1, sum * (isum-1), s, checkL);  // 아무 자음이나 L을 제외)
                    backtrack(idx + 1, sum, s, true);   // L을 선택
                }else{
                    backtrack(idx + 1, sum * isum, s, checkL);  // 아무 자음이나
                }
            }
        }
    }

}

// 즐거운 단어
int main(){
    bool checkL = false;

    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '_'){
            v.push_back(i);
        }
        if(S[i] == 'L'){
            checkL = true;
        }
    }

    N = v.size();
    m['A'] = true, m['E'] = true, m['I'] = true, m['O'] = true, m['U'] = true;  // 자음 표시

    backtrack(0, 1, S, checkL);

    cout << result << "\n";

    return 0;
}