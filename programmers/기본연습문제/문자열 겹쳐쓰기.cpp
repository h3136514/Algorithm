#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    for(int i = s; i < s + overwrite_string.size(); i++){
        answer[i] = overwrite_string[i-s];
    }
        
    
    return answer;
}