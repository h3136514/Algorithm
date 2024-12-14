// 구현, 문자열
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;
string str;
vector<string> v;

// 줄번호
int main(){
    cin >> N;
    cin.ignore();   // 버퍼에 정수 값을 입력한 뒤 누른 엔터(‘\n’)가 그대로 남아있어서
    for(int i = 0; i < N; i++){
        getline(cin, str);
        v.push_back(str);
    }
    for(int i = 0; i < N; i++)
        cout << i+1 << ". " << v[i] <<"\n";

    return 0;
}