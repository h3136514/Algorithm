#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> numbers) {
    for(int i = 0; i < numbers.size(); i++){
        answer.push_back(numbers[i]*2);
    }    
    return answer;
}