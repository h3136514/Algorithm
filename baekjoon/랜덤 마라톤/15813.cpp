// 구현, 문자열
#include <iostream>
#include <string>

using namespace std;
int N, sum;
string str;

// 너의 이름은 몇 점이니? 
int main(){
    cin >> N;
    cin >> str;

    for(int i = 0; i < N; i++){
        sum += (int)str[i] - 64;
    }

    cout << sum << "\n";

    return 0;
}