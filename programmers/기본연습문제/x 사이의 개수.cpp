#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int cnt = 0;

vector<int> solution(string myString) {
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] == 'x'){
            answer.push_back(cnt);
            cnt = 0;
            continue;
        } 
        
        cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}