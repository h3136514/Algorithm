#include <string>
#include <vector>

using namespace std;
string answer = "";
bool check = false;

string solution(string n_str) {
    for(int i = 0; i < n_str.size(); i++){
        if(check){
            answer += n_str[i];
            continue;
        }
        if(n_str[i] == '0')
            continue;
        
        check = true;
        answer += n_str[i];
    }
    
    return answer;
}