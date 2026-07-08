#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string myString, string pat) {
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] >= 'a'){
            myString[i] -= 32;
        }
    }
    for(int i = 0; i < pat.size(); i++){
        if(pat[i] >= 'a'){
            pat[i] -= 32;
        }
    }
    
    answer = (myString.find(pat) == string::npos) ? 0: 1;
    
    return answer;
}