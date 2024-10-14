#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> m;

// 매일 다른 옷을 조합하여 옷 입기
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(vector<string> v : clothes){
        m[v[1]]++;
    }
    
    for(auto i : m){
        answer *= (i.second+1);
    }
    
    answer -= 1;    // 아무것도 안입는 경우 제외
    
    return answer;
}