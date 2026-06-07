#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int a, int b) {
    string s = to_string(a) + to_string(b);
    
    answer = max((stoi)(s), 2*a*b);
    
    return answer;
}