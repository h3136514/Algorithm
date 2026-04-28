#include <string>
#include <vector>

using namespace std;
int mode = 0;
string answer = "";

string solution(string code) {
    for(int i = 0; i < code.size(); i++){
        if(code[i] == '1'){
            mode = (mode == 1) ? 0 : 1;
            continue;
        }
        
        if(mode && i%2 != 0){
            answer += code[i];
        }else if(!mode && i%2 == 0){
            answer += code[i];
        }
    }
    
    if(answer.size() == 0)
        answer =  "EMPTY";
    
    return answer;
}