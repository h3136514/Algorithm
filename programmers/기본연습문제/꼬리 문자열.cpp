#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(vector<string> str_list, string ex) {
    for(int i = 0; i < str_list.size(); i++){
        if(str_list[i].find(ex) == string::npos)
            answer += str_list[i];     
    }
    
    return answer;
}