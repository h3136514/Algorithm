#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n, int k) {
    answer = 12000 * n;
    int drink = n/10;
    
    int cal = (drink <= k) ? 2000*(k-drink) : 0;
    answer += cal;
    
    return answer;
}