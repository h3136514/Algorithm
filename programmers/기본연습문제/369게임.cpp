#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int order) {
    string s = to_string(order);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '3' || s[i] == '6' || s[i] == '9')
            answer++;
    }
    
    return answer;
}