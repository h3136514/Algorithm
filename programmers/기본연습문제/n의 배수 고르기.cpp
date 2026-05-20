#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(int n, vector<int> numlist) {
    for(int i = 0; i < numlist.size(); i++){
        if(numlist[i] % n == 0)
            answer.push_back(numlist[i]);
    }    
    return answer;
}