// BFS
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
unordered_map<string, bool> m; // 방문체크
queue<pair<string, int>> q;

// 한 개의 알파벳만 다른지 확인 
bool check(string a, string b){
    int cnt = 0;
    for(int i = 0; i <a.size(); i++){
        if(a[i] != b[i])
            cnt++;
    }
    if(cnt == 1)
        return true;
    
    return false;
}

int bfs(string startStr, string endStr){
    m[startStr] = 1;    //방문
    q.push({startStr, 0});
    
    while(!q.empty()){
        string str = q.front().first;
        int currentCNT = q.front().second;
        q.pop();
        
        if(str == endStr)
            return currentCNT;
        
        for(auto i : m){
            string is = i.first;
            if(m[is] == 0 && check(str, is)){
                m[is] = 1;
                q.push({is, currentCNT + 1});
            } 
        }
    }
    
    return 0;
}


//  규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정 찾기 (한 번에 한 개의 알파벳만 바꿀 수 있고 words에 있는 단어로만 변환가능(문자 길이는 같음))
int solution(string begin, string target, vector<string> words) {
    for(int i = 0; i < words.size(); i++)
        m[words[i]] = 0;
    
    return bfs(begin, target);
}