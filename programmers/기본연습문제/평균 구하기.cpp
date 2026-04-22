#include <string>
#include <vector>

using namespace std;
double answer = 0;

double solution(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++){
        answer += arr[i];    
    }   
    answer /= arr.size();
    
    return answer;
}