#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
int N;
string s[20001];
unordered_map<string, int> m;
priority_queue<pair<int, pair<int, int>>> q;

// 비슷한 단어
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> s[i];
    
    for(int i = 0; i < N; i++){
        for(int j = s[i].size(); j > 0; j--){
            auto str = m.find(s[i].substr(0, j));

            if(str == m.end()){ // 처음 나온 부분 문자열
                m[s[i].substr(0, j)] = i;
            }else{
                q.push({j, {-m[s[i].substr(0, j)], -i}});   // 이미 있는 부분 문자열이면 후보
            }
        }
    }

    string a = s[-q.top().second.first];
    string b = s[-q.top().second.second];

    cout << a << "\n";
    cout << b << "\n";

    return 0;
}