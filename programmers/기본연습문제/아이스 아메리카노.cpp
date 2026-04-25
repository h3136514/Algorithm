#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(int money) {
    answer.push_back(money/5500);
    answer.push_back(money%5500);
    
    return answer;
}