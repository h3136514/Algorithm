#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(vector<string> arr) {
    for(int i = 0; i < arr.size(); i++){
        answer += arr[i];
    }
    
    return answer;
}