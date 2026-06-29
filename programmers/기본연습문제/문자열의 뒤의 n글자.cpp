#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string my_string, int n) {
    for(int i = my_string.size()-n; i < my_string.size(); i++){
        answer += my_string[i];
    }
    
    return answer;
}