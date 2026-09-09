#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n) {
    for(int i = 2; i < n; i++){
        if(n%i == 1){
            answer = i;
            break;
        }
    }    
    return answer;
}