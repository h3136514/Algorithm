#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    
    for (int i = 0; i < queries.size(); i++) {
        int s = queries[i][0];
        int e = queries[i][1];
        
        // answer의 s번째 인덱스부터 e번째 인덱스까지 뒤집기(끝나는 지점은 e + 1로 지정해야 e번 인덱스까지 포함됨)
        reverse(answer.begin() + s, answer.begin() + e + 1);
    }
    
    return answer;
}