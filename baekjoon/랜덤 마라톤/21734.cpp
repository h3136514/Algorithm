// 구현, 문자열
#include <iostream>
#include <string>

using namespace std;
string str;
int sum, num;

// SMUPC의 등장
int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        num = int(str[i]);
        
        sum = num/100 + (num%100)/10 + num%10;
        for(int j = 0; j < sum; j++)
            cout << str[i];
        cout << "\n";
    }

    return 0;
}
