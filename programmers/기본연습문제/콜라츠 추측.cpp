#include <string>
#include <vector>

using namespace std;
int answer = -1;

int solution(int num) {
    long long tmp = num;
    if(num == 1)
        return 0;
    
    for(int i = 1; i <= 500; i++){    
        if(tmp % 2 == 0)
            tmp /= 2;
        else{
            tmp *= 3;
            tmp += 1;
        }
        
        if(tmp == 1){
            answer = i;
            break;
        }
    }
    
    return answer;
}