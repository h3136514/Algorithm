#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(long long n) {
    while(n > 0){
        answer.push_back(n%10);
        n /= 10;
    }
    
    return answer;
}