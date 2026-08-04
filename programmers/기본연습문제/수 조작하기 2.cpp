#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(vector<int> numLog) {
    for(int i = 1; i < numLog.size(); i++){
        int gap = numLog[i] - numLog[i-1];
        if(gap == 1)
            answer += "w";
        else if(gap == -1)
            answer += "s";
        else if(gap == 10)
            answer += "d";
        else
            answer += "a";
    }
    
    return answer;
}