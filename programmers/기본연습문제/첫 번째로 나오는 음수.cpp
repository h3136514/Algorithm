#include <string>
#include <vector>

using namespace std;
int answer = -1;

int solution(vector<int> num_list) {
    for(int i = 0; i < num_list.size(); i++){
        if(num_list[i] < 0){
            answer = i;
            break;
        }    
    }
    
    return answer;
}