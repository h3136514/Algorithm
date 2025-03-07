// 자료구조, 문자열, 맵
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
int N, S, t, CNT;
string str;
map<string, int> m;
set<string> s;

// KCPC에 등장할 알고리즘 맞히기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S >> t;
        for(int j = 0; j < t; j++){
            cin >> str;
            m[str] ++;
            CNT = max(CNT, m[str]);
        }
    }
    for(auto tag : m){
        if(tag.second == CNT)
            s.insert(tag.first);
    }

    if(s.size() > 1)
        cout << "-1\n";
    else
        for(string maxTag : s)
            cout << maxTag << "\n";

    return 0;
}