#include <iostream>
#include <string>

using namespace std;
int CNT = 1;
string s;

// 정수의 개수
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',')
            CNT++;
    }

    cout << CNT << "\n";

    return 0;
}