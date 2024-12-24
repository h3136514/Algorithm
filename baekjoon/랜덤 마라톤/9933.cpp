// 구현, 문자열, 집합과 맵
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;
int N;
string str, password;
unordered_set<string> s;

// 민균이의 비밀번호
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        s.insert(str);

        reverse(str.begin(), str.end());

        if(s.find(str) != s.end()){
            password = str;
        }
    }

    cout << password.size() << " " << password[password.size()/2] << "\n";

    return 0;
}