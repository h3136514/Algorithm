#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> map;     //participant를 나타낼 해시테이블 

// 완주하지 못한 선수 이름 찾기 (시간복잡도 : O(N)
string solution(vector<string> participant, vector<string> completion) {
    //각 참가자들을 해시 테이블에 추가( 키 : 이름, 값 : 해당 이름의 명 수)
    for(string runner : participant){
        //만약 이미 테이블에 있으면 명수 만 증가
        if(map.count(runner)){
            int cnt = map.at(runner);
            map[runner] = ++cnt;
        }else
            map.insert({runner, 1});
    }
    // 더 간단하게 가능
    /*
    for (int i = 0; i < participant.size(); i++)
        map[participant[i]]++;
    */
    
    // 참가자 정보가 저장된 해시 테이블에서, 완주한 선수들을 제외
    for(string runner : completion){
        int cnt = map.at(runner);

        // 남아있는 동일한 이름이 한명이면 삭제
        if(cnt == 1)
            map.erase(runner);
        else // 명수 감소
            map[runner] = --cnt;
    }
    
    //마지막 남은 한 선수의 이름을 반환 
    return map.begin() -> first;   
}

#include <iostream>

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << endl; // "leo"
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << endl; // "vinko"
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << endl; // "mislav"
    return 0;

}
// 정렬을 활용한 풀이(map 사용X, 시간복잡도 : O(NlogN))
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }

    return participant[participant.size() - 1];
}

*/