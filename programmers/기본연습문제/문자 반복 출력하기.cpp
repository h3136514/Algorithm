#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string my_string, int n) {
    for(int i = 0; i < my_string.size(); i++){
        for(int j = 0; j < n; j++){
            answer += my_string[i];
        }
    }    
    return answer;
}