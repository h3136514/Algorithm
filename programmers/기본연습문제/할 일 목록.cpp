#include <string>
#include <vector>

using namespace std;
vector<string> answer;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    for(int i = 0; i < finished.size(); i++){
        if(!finished[i])
            answer.push_back(todo_list[i]);
    }
    
    return answer;
}