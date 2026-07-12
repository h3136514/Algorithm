#include <string>
#include <vector>

using namespace std;
string answer = "";
string solution(string rny_string) {
    for(int i = 0; i < rny_string.size(); i++){
        if(rny_string[i] == 'm')
            answer += "rn";
        else
            answer += rny_string[i];
    }
    
    return answer;
}