#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int N, answer = 0;
set<int> s;
vector<int> v;

int solution(vector<int> elements) {
    N = elements.size();
    v = elements;
    
    for(int i = 0; i < N; i++)
        v.push_back(elements[i]);
    
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < N; j ++){
            int sum = 0;
            for(int k = j; k < j + i; k++){
                sum += v[k];
            }
        
            s.insert(sum);       
        }
    }
    
    answer = s.size();
    
    return answer;
}