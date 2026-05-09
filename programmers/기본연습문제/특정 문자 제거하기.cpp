#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string my_string, string letter) {
    char c = letter[0];
    for(int i = 0; i < my_string.size(); i++){
        if(my_string[i] != c)
            answer += my_string[i];
    }
    
    return answer;
}