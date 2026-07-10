#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string myString) {
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] < 97)
            answer += myString[i] + 32;
        else
            answer += myString[i];
    }
    
    return answer;
}