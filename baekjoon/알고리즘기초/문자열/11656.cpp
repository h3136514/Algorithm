#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string S;
vector<string> v;

// 접미사 배열
int main(){
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        v.push_back(S.substr(i, S.size() - i));
    }
    sort(v.begin(), v.end());   // 사전순 정렬

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";

    return 0;
}