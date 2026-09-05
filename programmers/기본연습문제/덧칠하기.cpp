#include <string>
#include <vector>

using namespace std;
int paint = 0, answer = 0;

int solution(int n, int m, vector<int> section) {
    int nSize = section.size();
    for(int i = 0; i < nSize; i++){
        if(paint >= section[i])
            continue;
        
        paint = section[i] + m - 1;
        answer++;
    }
    
    return answer;
}