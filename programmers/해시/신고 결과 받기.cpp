#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;
unordered_map<string, unordered_set<string>> reported;  //해당 id를 신고한 사람들
unordered_map<string, unordered_set<string>> reporting; //해당 id가 신고한 사람들
string reportedId, reportingId;
int cnt;

// k번 이상 신고된 유저는 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송할 때 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 반환(report길이: N, reporting의 길이: M, 시간복잡도 : O(N+M))
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // 신고 처리(저장)
    for(int i=0; i < report.size(); i++){
        stringstream ss(report[i]);
        ss >> reportingId >> reportedId;
        
        reporting[reportingId].insert(reportedId);
        reported[reportedId].insert(reportingId);
    }
    
    // 신고 처리 결과
    for(int i=0; i < id_list.size(); i++){
        cnt = 0;
         // 신고한 사람이 없을 경우 
        if(reporting.find(id_list[i]) == reporting.end()){
            answer.push_back(0);
            continue;
        }
        
         unordered_set<string> ids = reporting[id_list[i]]; // 신고한 사람에 대해서 신고한 사람들
        // 신고한 사람들의 신고 처리 결과 계산
        for(auto itr = ids.begin(); itr != ids.end(); itr++){
            reportedId = *itr; // 신고된 사람의 id
            // k번 이상 신고되었으므로 이용정지
            if(reported[reportedId].size() >= k)
                cnt++;
        }
         
        answer.push_back(cnt); 
    }
    
    return answer;
}


#include <iostream>

void print(vector<int> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
  cout << endl;
}

int main()
{
    print(solution({"muzi", "frodo","apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2)); //출력값 : 2 1 1 0
    print(solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3)); //출력값 : 0 0 

    return 0;
}

// 처리 결과를 매핑으로 저장해서 처리하는 방법
/*
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  unordered_map<string, unordered_set<string>> reported_user; // 신고당한 유저 - 신고 유저 집합
  unordered_map<string, int> count; //  메일을 받은 유저 - 받은 횟수

  // 신고 기록 순회
  for (string r : report) {
    // 각 report에서 user_id와 report_id를 분리하고 reported_user에 추가 
    stringstream ss(r);
    string user_id, reported_id;
    ss >> user_id >> reported_id;
    reported_user[reported_id].insert(user_id);
  }

  for (auto [reported_id, user_id_lst] : reported_user) {
    // k명 이상에게 신고당했는지 확인
    if (user_id_lst.size() >= k) {
      // 각 uid가 신고 결과를 받은 횟수를 기록
      for (string uid : user_id_lst) {
        count[uid]++;
      }
    }
  }

  vector<int> answer;
  // 각 아이디별 메일을 받은 횟수를 id_list 순서대로 answer에 추가
  for (string id : id_list) {
    answer.push_back(count[id]);
  }

  return answer;
}
*/