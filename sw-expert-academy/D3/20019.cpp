// 회문의 회문
#include <iostream>
#include <string>

using namespace std;
int T, N;
string S;

// 회문 검사
bool checkPalindrome(string str){
    bool check = true;
    for(int i = 0; i < str.size()/2; i++){
        if(str[i] != str[str.size() - 1 - i]){
            check = false;
            break;
        }
    }

    return check;
}

int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> S;
        N = S.size();
        string firstS = S.substr(0, (N-1)/2);
        string endS = S.substr(N-1, (N-1)/2);
        if(!checkPalindrome(S) || !checkPalindrome(firstS) || !checkPalindrome(endS)){
            cout << "#" << i << " " << "NO\n";
            continue;
        }
        
        cout << "#" << i << " " << "YES\n";
    }

    return 0;
}