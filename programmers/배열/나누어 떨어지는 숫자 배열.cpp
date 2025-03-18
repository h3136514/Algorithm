#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] >= divisor && arr[i]%divisor == 0)
            answer.push_back(arr[i]);
    }
    
    if(answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}
