#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int num1, int num2) {
    double a = (double)num1 / (double)num2;
    answer = (int)(a*1000);
    
    return answer;
}