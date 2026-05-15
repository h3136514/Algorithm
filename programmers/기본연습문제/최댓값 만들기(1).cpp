#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<int> numbers) {
    sort(numbers.rbegin(), numbers.rend());
    answer = numbers[0] * numbers[1];
    
    return answer;
}