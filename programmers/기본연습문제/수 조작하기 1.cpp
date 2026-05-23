#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n, string control) {
    answer = n;
    
    for(int i = 0; i < control.size(); i++){
        if(control[i] == 'w'){
            answer++;
        }else if(control[i] == 's'){
            answer--;
        }else if(control[i] == 'd'){
            answer += 10;
        }else{
            answer -= 10;
        }
    }
    
    return answer;
}