#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string str1, string str2) {
    if(str1.find(str2) == string::npos)
        answer = 2;
    else
        answer = 1;
    
    return answer;
}