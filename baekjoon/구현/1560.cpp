// 큰 수 연산
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string N;

// 두 문자열 더하기
string addString(string a, string b){
    string s = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        s += to_string(sum % 10);
        carry = sum / 10;
    }

    reverse(s.begin(), s.end());
    return s;
}

// 문자열 빼기
string minusString(string a, int n){
    string s = "";
    int idx = a.size() -1;
    int carry = 2;

    for(int i = idx; i >= 0; i--){
        int num = a[i] -'0';
        num -= carry;
        if(num < 0){
            num += 10;
            carry = 1;
        }else
            carry = 0;
        
        if(i == 0 && num == 0)
            continue;
        s += to_string(num);
    }

    reverse(s.begin(), s.end());
    return s;
}

// 비숍
int main(){
    cin >> N;
    
    if(N.size()== 1 && stoi(N) <= 2)
        cout << N << "\n";
    else{
        cout << addString(N, minusString(N, 2)) << "\n";
    }

    return 0;
}