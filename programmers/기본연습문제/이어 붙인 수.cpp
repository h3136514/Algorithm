#include <string>
#include <vector>

using namespace std;
int odd, even, answer = 0;
string oddStr = "", evenStr = "";

int solution(vector<int> num_list) {
    for(int i = 0; i < num_list.size(); i++){
        if(num_list[i]%2 == 0)
            evenStr +=to_string(num_list[i]);
        else
            oddStr +=to_string(num_list[i]);
    }
    
    answer = stoi(evenStr) + stoi(oddStr);
    
    return answer;
}