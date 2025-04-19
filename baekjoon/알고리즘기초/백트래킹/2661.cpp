#include <iostream>
#include <string>

using namespace std;
int N;
string str;
bool finish;

// 좋은 수열인지 확인
bool check(string s){
    // 마지막 인덱스 기준으로 1 ~ (현재길이/2)까지 같은 부분 수열이 있는지 비교
    for(int j = 1; j <= s.size()/2; j++){
        if(s.substr(s.size()- j, j) == s.substr(s.size()- 2*j, j))  
            return false;
    }

    return true;
}

void backtracking(int cnt,  string s){
    if(finish)
        return;

    if(cnt == N){
        cout << s << "\n";
        finish = true;

        return;
    }

    for(int i = 1; i <= 3; i++){
        string tmp = s;
        tmp += i + '0';
        if(check(tmp))
            backtracking(cnt + 1,  tmp);
    }
}

// 좋은수열
int main(){
    cin >> N;

    backtracking(0, "");

    return 0;
}