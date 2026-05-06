#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n) {
    answer = (n % 7 == 0) ? n/7 : n/7 + 1;
    
    return answer;
}