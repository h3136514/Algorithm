#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fail[501];
int challenge[501];

// 정렬 기준 정의
bool compare(pair<int, float> a, pair<int, float> b) {
    if(a.second == b.second){
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 각 스테이지의 실패한 인원수와, 도전한 적이 있는 인원수를 구함 
    for(int i = 0; i < stages.size(); i++ ) {
        fail[stages[i]]++;
        for(int j = 1; j <= stages[i]; j++ ) {
            challenge[j]++;
        }
    }
    
    // 각 스테이지에 대한 실패율을 저장하는 공간
    vector<pair<int, float>> failRate(N);
    
    for(int i = 0; i < N; i++) {
        failRate[i].first = i + 1;
        
        if(challenge[i + 1] == 0)
            failRate[i].second = 0;
        else
            failRate[i].second = (float)fail[i + 1]/challenge[i + 1];
       
    }
    
    sort(failRate.begin(), failRate.end(), compare);
    for(int i = 0; i < failRate.size(); i++) {
        answer.push_back(failRate[i].first);
    }
    
    return answer;
}

#include<iostream>

int main() {
    vector<int> arr = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    for(int i =0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}