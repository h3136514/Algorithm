#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    for(int i = num1; i <= num2; i++)
        answer.push_back(numbers[i]);
    
    return answer;
}