#include <string>
#include <vector>

#define INF 987654321
using namespace std;
string target, tmp;
int CNT = INF, visitied[21];

void dfs(int cnt, int idx, string s){    
    if(s[idx] != target[idx]){
        int num = int(target[idx] - s[idx]);
        cnt += (num > 13) ? 26 - num : num;    // 위, 아래 이동
        s[idx] = target[idx];
    }
    
    // 문자열이 같으면 탈출
    if(target == s){
        CNT = min(CNT, cnt);
        
        return;
    }
    
    // 왼쪽 이동
    int leftIdx = (idx == 0) ? s.size() -1 : idx - 1;
    if(visitied[leftIdx] < 2){  // 무한반복을 없애기 위해(한번 왔다갔다는 가능)
        visitied[leftIdx]++;
        dfs(cnt+1, leftIdx, s);
        visitied[leftIdx]--;
    }
    // 오른쪽 이동
    int rightIdx = (idx == s.size()-1) ? 0 : idx + 1;
    if(visitied[rightIdx] < 2){
        visitied[rightIdx]++;
        dfs(cnt+1, rightIdx, s);
        visitied[rightIdx]--;
    }
    
}

int solution(string name) {
    target = name;
    
    for(int i = 0; i < name.size(); i++)
        tmp += 'A';
    
    visitied[0] = 1;    // 맨처음 방문 표시
    dfs(0, 0, tmp);
    
    if(target == tmp)   // 'A'로만 이루어진 문자
        CNT = 0;
    
    return CNT;
}