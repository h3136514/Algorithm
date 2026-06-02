#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int hp) {
    answer += hp/5;
    hp = hp%5;
    answer += hp/3;
    hp = hp%3;
    answer += hp;
    
    return answer;
}