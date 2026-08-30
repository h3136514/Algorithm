#include <string>
#include <vector>

using namespace std;
long long answer = 0;
int s, e;

long long solution(int a, int b) {
    if(a < b)
        s = a, e = b;
    else
        s = b, e = a;
    
    for(int i = s; i <= e; i++){
        answer += i;
    } 
    
    return answer;
}