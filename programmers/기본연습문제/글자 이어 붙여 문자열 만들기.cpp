#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string my_string, vector<int> index_list) {
    for(int i = 0; i < index_list.size(); i++){
        answer +=  my_string[index_list[i]];
    }
    
    return answer;
}