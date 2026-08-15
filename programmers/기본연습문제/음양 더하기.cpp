#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(vector<int> absolutes, vector<bool> signs) {
    for(int i = 0; i < absolutes.size(); i++){
        if(!signs[i])
            absolutes[i] *= -1;
        answer += absolutes[i];
    }
    
    return answer;
}