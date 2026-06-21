#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int slice, int n) {
    answer = (n%slice == 0) ? n/slice : (n/slice) + 1;  
        
    return answer;
}