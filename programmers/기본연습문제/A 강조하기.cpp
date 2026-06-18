#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = myString;
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] ==' ')
            continue;
        
        if(answer[i] < 97)
            answer[i] += 32;
        if(answer[i] == 'a')
            answer[i] = 'A';
    }
    
    return answer;
}