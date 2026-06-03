#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int num, int n) {
    answer = (num % n == 0) ? 1 : 0;
    
    return answer;
}