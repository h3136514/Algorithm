#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n) {
    for(int i = 1; i <= n; i++){
        if(n%i == 0)
            answer += i;
    }
    
    return answer;
}