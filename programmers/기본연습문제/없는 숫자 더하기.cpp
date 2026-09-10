#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(vector<int> numbers) {
    for(int i = 1; i <= 9; i++)
        answer += i;
    
    for(auto a : numbers)
        answer -= a;
    
    return answer;
}