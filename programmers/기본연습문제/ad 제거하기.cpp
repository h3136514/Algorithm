#include <string>
#include <vector>

using namespace std;
vector<string> answer;

vector<string> solution(vector<string> strArr) {
    for(int i = 0; i < strArr.size(); i++){
        if(strArr[i].find("ad") == string::npos){
            answer.push_back(strArr[i]);
        }    
    }
    
    return answer;
}