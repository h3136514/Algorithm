#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<int> numbers) {
    int n = numbers.size();
    sort(numbers.begin(), numbers.end());
    answer = max(numbers[0]*numbers[1], numbers[n-1]*numbers[n-2]);
    
    return answer;
}