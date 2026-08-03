#include <string>
#include <vector>

using namespace std;
int add = 0, even = 0, answer = 0;

int solution(vector<int> num_list) {
    for(int i = 0; i < num_list.size(); i++){
        if(i % 2 == 0)
            even += num_list[i];
        else
            add += num_list[i];
    }
    
    answer = max(add, even);
    
    return answer;
}