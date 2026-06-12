#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    
    for(int i = 5; i < num_list.size(); i++){
        answer.push_back(num_list[i]);
    }
    
    return answer;
}