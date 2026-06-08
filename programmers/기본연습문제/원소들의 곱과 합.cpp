#include <string>
#include <vector>

using namespace std;
int answer = 0, sum = 0, mul = 1;

int solution(vector<int> num_list) {
    for(int i = 0; i < num_list.size(); i++){
        sum += num_list[i];
        mul *= num_list[i];
    }
    answer = (sum*sum < mul) ? 0 : 1;
     
    return answer;
}