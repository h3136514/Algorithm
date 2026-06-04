#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> num_list, int n) {
    for(int i = n-1; i < num_list.size(); i++){
        answer.push_back(num_list[i]);
    }   
    
    return answer;
}