#include <string>
#include <vector>

using namespace std;
int answer = 0;
int solution(int n) {
    while(n > 0){
        answer += n%10;
        n /= 10;
    }
    return answer;
}