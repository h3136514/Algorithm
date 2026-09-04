#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(int num) {
    if(num % 2 == 0)
        answer = "Even";
    else
        answer = "Odd";
    
    return answer;
}