#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
    
vector<int> solution(vector<int> arr) {
    if(arr.size() == 1)
        answer.push_back(-1);
    else{
        int minNum = arr[0];
        for(int i = 1; i < arr.size(); i++){
            minNum = min(arr[i], minNum);
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(minNum != arr[i]){
                answer.push_back(arr[i]);
            }
        }
    }
    
    return answer;
}