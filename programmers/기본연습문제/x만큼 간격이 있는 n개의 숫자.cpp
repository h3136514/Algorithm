#include <string>
#include <vector>

using namespace std;
vector<long long> answer;
vector<long long> solution(int x, int n) {
    long long tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += x;
        answer.push_back(tmp);
    }
    
    return answer;
}