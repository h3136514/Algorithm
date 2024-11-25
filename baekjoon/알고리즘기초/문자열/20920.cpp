#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
int N, M;
string s;
vector<string> v;
unordered_map<string, int> m;

// 정렬 우선순위
bool compare(string a, string b){
    if(m[a] == m[b]){
        if(a.size() == b.size()){
            return a < b;
        }else
            return a.size() > b.size();
    }else
        return m[a] > m[b];
}

// 영단어 암기는 괴로워
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s.size() >= M){
            m[s]++;
        }
    }

    // 영어 단어 벡터에 추가
    for(auto str : m){
        v.push_back(str.first);
    }

    // 정렬
    sort(v.begin(), v.end(), compare);

    for(string str : v){
        cout << str << "\n";
    }

    return 0;
}