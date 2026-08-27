#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int a = x, b = 0;
    while(a > 0){
        b += a%10;
        a /= 10;
    }
    
    if(x%b != 0)
        answer = false;
    
    return answer;
}