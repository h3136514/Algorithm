#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string my_string, int k) {
    for(int i = 0; i < k; i++){
        answer += my_string;
    }
    
    return answer;
}