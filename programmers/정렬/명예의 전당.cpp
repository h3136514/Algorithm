// https://school.programmers.co.kr/learn/courses/30/lessons/138477
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, answer;

vector<int> solution(int k, vector<int> score) {
    for(int i = 0; i < score.size(); i++){
        if(i < k || v.back() < score[i]){
            v.push_back(score[i]);
            sort(v.rbegin(), v.rend());
            
            if(v.size() > k)
                v.pop_back();
            
            answer.push_back(v.back());
        }else
            answer.push_back(v.back());
    }
    
    return answer;
}