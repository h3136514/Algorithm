#include <string>
#include <iostream>

using namespace std;
bool answer = true;
int p = 0, y = 0;

bool solution(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            p++;
        else if(s[i] == 'y' || s[i] == 'Y')
            y++;
    }
    
    answer = (y == p) ? true : false;

    return answer;
}