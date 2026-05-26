#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(vector<int> array, int n) {
    for(int i = 0; i < array.size(); i++){
        if(array[i] == n)
            answer++;
    }
    
    return answer;
}