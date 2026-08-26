#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string s) {
    string st ="";
    if(s[0] == '-'){
        st = s.substr(1);
        answer = -stoi(st);
    }else{
        st = s;
        answer = stoi(st);
    }
        
    return answer;
}