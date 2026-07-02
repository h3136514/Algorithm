#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string myString, string pat) {
    for(int i = 0; i < myString.size(); i++){
        myString[i] = myString[i] == 'A'? 'B' : 'A';
    }
    
    answer = (myString.find(pat) != string::npos) ? 1 : 0;
    
    return answer;
}