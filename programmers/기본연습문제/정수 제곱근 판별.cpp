#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long a = sqrt(n);
    if (a*a == n) {	// 양의 정수x의 제곱인 경우
        answer=pow(a+1,2);
    }
    else {	// 아닌 경우
        answer=-1;
    }
    
    return answer;
}