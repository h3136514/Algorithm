#include <string>
#include <vector>
#include <set>

using namespace std;

// 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return (시간복잡도 : O(N*NlogN))
vector<int> solution(vector<int> numbers) {
    set<int> sum;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i+1; j < numbers.size(); j++) {
            sum.insert(numbers[i] + numbers[j]);  
        }
    }
    
    vector<int> answer(sum.begin(), sum.end());
    return answer;
}




// 배열 인덱스를 이용해 중복체크
/*
int N[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers.size(); j++) {
            if(i == j)
                continue;
            N[numbers[i] + numbers[j]] = 1;  
        }
    }
    
    for(int i = 0; i < 201; i++) {
        if(N[i])
            answer.push_back(i);
    }
    
    return answer;
}
*/