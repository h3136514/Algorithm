#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n, int t) {
    answer = n;
    for(int i = 1; i <= t; i++){
        answer *= 2;
    }
    return answer;
}