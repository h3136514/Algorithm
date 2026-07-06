#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> arr, int k) {
    for(int i = 0; i < arr.size(); i++){
        if(k%2 == 0)
            answer.push_back(arr[i] + k);
        else
            answer.push_back(arr[i] * k);
    }
    
    return answer;
}