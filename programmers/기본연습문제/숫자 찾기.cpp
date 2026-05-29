#include <string>
#include <vector>

using namespace std;
int answer = -1;

int solution(int num, int k) {
    string s = to_string(num);
    for(int i = 0; i < s.size(); i++){
        int target = s[i] - '0';
        if(target == k){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}