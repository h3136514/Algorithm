#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int a, int b, int n) {
    while(n >= a){
        int add = (n / a) * b;
        answer += add;
        int tmp = n % a;
        n = add + tmp;
    }
    
    return answer;
}