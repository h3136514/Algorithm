// 구현, 문자열, 파싱
#include <iostream>
#include <string>

using namespace std;
int sum;
string str;

// 머신 코드
int main(){
    cin >> str;

    int cnt  = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            sum += (4 - cnt % 4 ) % 4;  // 대문자 + 뒤에 있는 소문자들의 개수의 합이 4의 배수
            cnt = 0;
        }

        cnt++;
    }

    cout << sum << "\n";

    return 0;
}