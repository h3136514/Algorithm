#include <iostream>
#include <string>

using namespace std;
int N;
string s;

bool check(char c){
    if(c < 97)
        return true;
    else
        return false;
}

// 입실 관리
int main(){
    cin >> N;
    while(N--){
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(check(s[i]))
                s[i] += 32;
        }

        cout << s << "\n";
    }

    return 0;
}