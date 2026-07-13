#include <string>
#include <vector>

using namespace std;

int answer = 0;
int solution(int n) {
    for(int i = 1; i <= 100; i++){
        if(n > i*6)
            continue;
        if((i*6)%n == 0){
            answer = i;
            break;
        }
    }
    
    return answer;
}