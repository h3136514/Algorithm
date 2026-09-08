#include <string>
#include <vector>

using namespace std;
string answer = "김서방은 ";

string solution(vector<string> seoul) {
    for(int i = 0; i < seoul.size(); i++){
        if("Kim" == seoul[i]){
            answer += to_string(i);
            break;
        }    
    }
    answer += "에 있다";
    
    return answer;
}