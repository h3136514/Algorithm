#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string rsp) {
    for(int i = 0; i < rsp.size(); i++){
        if(rsp[i] == '2')
            answer += "0";
        else if(rsp[i] == '0')
            answer += "5";
        else
            answer += "2";
    }
    
    return answer;
}