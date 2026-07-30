#include <string>
#include <vector>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    answer = arr;
    for(vector<int> a: queries){
        int tmp = answer[a[0]];
        answer[a[0]] = answer[a[1]];
        answer[a[1]] = tmp;
    }
    
    return answer;
}