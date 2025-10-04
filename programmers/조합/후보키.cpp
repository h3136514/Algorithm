#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<vector<string>> rela;
set<vector<string>> s;
int N, M, answer;
vector<string> visit;
map<string, int> m;

// 최소성 확인
bool checking(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j])
                cnt++;
        }
    }
    
    if(cnt == b.size() || cnt == a.size())
        return false;
    
    return true;
}

void backtrack(int maxCnt, int cnt, int idx, string v){
    if(maxCnt == cnt){
        bool check = false;
        for(auto st : m){
            if(!checking(st.first, v)){
                check = true;
                break;
            }
        }
        if(check)
            return;
        
        for(int i = 0; i < N; i++){
            vector<string> tmp;
            for(int j = 0; j < cnt; j++){
                int idx = v[j] - '0';
                tmp.push_back(rela[i][idx]);
            }
            s.insert(tmp);
            tmp.clear();
        }
        
        if(s.size() == N){  //유일성 확인
            m[v] = 1;
            answer++;
        }
        s.clear();
        
        return;
    }
    
    for(int i = idx; i < M; i++){
        backtrack(maxCnt, cnt+1, i+1, v +to_string(i));
    }
}

int solution(vector<vector<string>> relation) {
    N = relation.size();
    M = relation[0].size();
    rela = relation;

    for(int i = 1; i <= M; i++){
        backtrack(i, 0, 0, "");
    }
    
    return answer;
}