#include <string>
#include <vector>

using namespace std;
vector<string> answer;

vector<string> solution(vector<string> names) {
    for(int i = 0; i < names.size(); i++){
        if(i%5 == 0)
            answer.push_back(names[i]);
    }
    
    return answer;
}