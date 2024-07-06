#include <string>
#include <vector>
#include <algorithm> //max_element()사용을 위해

using namespace std;

int maxScore, scores[3];
vector<int> arr1 = {1, 2, 3, 4, 5};
vector<int> arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

// 수포자 삼인방은 모의고사에 특정패턴으로 번호를 찍는다. 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 오른차순으로 배열에 담아 return (시간복잡도 : O(N))
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i = 0; i < answers.size(); i++) {
        if(arr1[i % arr1.size()] == answers[i]){
            scores[0]++;
            if(maxScore < scores[0])
                maxScore = scores[0];
        }
        if(arr2[i % arr2.size()] == answers[i]){
            scores[1]++;
            if(maxScore < scores[1])
                maxScore = scores[1];
        }
        if(arr3[i % arr3.size()] == answers[i]){
            scores[2]++;
            if(maxScore < scores[2])
                maxScore = scores[2];
        }
        
    }
    // scores가 'vector<int> scores(3);'로 선언했으면 'int maxScore = *max_element(scores.begin(), scores.end());'로 가장 큰 값을 구할 수 있음

    for(int i = 0; i < 3; i++) {
        if(maxScore == scores[i])
            answer.push_back(i+1);
    }
    
    return answer;
}
