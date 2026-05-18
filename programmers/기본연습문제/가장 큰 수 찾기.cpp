#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> array) {
    answer.resize(2);
    answer[0] = array[0];
    answer[1] = 0;
    for(int i = 1; i < array.size(); i++){
        if(answer[0] < array[i]){
             answer[0] = array[i];
             answer[1] = i;
        }
    }
    
    return answer;
}