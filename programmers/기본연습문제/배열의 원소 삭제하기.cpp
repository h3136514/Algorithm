#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int num[1001];

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for(int i = 0; i < delete_list.size(); i++){
        num[delete_list[i]] = 1;
    }
    
    for(int i = 0; i < arr.size(); i++){
        if(!num[arr[i]])
            answer.push_back(arr[i]);
    }
    
    return answer;
}