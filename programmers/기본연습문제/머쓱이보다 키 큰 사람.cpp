#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<int> array, int height) {   
    sort(array.rbegin(), array.rend());
    for(int i = 0; i < array.size(); i++){
       if(array[i] <= height) 
           break;
        
        answer++;
    }
    
    return answer;
}