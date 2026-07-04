#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(string my_string, string is_suffix) {
    int idx = my_string.size()-is_suffix.size();
    
    string tmp = "";
    for(int i = idx; i < my_string.size(); i++){
        tmp += my_string[i];
    }
    
    answer = (tmp == is_suffix) ? 1 : 0;
    
    return answer;
}