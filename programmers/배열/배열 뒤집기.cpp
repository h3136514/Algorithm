#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    reverse(num_list.begin(), num_list.end());

    return num_list;
}

// reverse() 안사용하고
/* 
vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    for(int i = num_list.size()-1; i >= 0; i--)
        answer.push_back(num_list[i]);
    
    return answer;
}
    */