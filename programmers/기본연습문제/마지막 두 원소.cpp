#include <string>
#include <vector>

using namespace std;
vector<int> answer;
vector<int> solution(vector<int> num_list) {
    answer = num_list;
    int endIdx = num_list.size()-1;
    if(answer[endIdx-1] < answer[endIdx])
        answer.push_back(answer[endIdx] - answer[endIdx-1]);
    else
        answer.push_back(answer[endIdx]*2);
    
    return answer;
}