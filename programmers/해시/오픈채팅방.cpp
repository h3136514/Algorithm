#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;
unordered_map<string, string> name;
string command[3] ={"Enter", "Leave", "Change"};

// 채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 주어질 때, 모든 기록이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 반환(시간복잡도 : O(N))
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // 각 record에 대해서 명령어를 보고 id에 맞는 닉네임을 name에 저장
    for(int i=0; i < record.size(); i++){
        // 문자열을 스트림화
        stringstream ss(record[i]);
         // 공백 분리 결과를 저장할 배열
        vector<string> strs;
        
        string str;
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 백터에 저장
        while(getline(ss, str, ' ')){
            strs.push_back(str);
        }
        if(strs[0] == command[0] || strs[0] == command[2]){
            name[strs[1]] = strs[2];
        }
    }

    // 각 record에 대해서 Enter 및 Change 명령어의 경우 최종 닉네임과 정해진 문자열을 answer에 추가
    for(int i=0; i < record.size(); i++){
        string result ="";
        // 문자열을 스트림화
        stringstream ss(record[i]);
         // 공백 분리 결과를 저장할 배열
        vector<string> strs;
        
        string str;
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 백터에 저장
        while(getline(ss, str, ' ')){
            strs.push_back(str);
        }
        if(strs[0] == command[0])
            result += name[strs[1]] + "님이 들어왔습니다.";
        else if(strs[0] == command[1])
            result += name[strs[1]] + "님이 나갔습니다.";
        else
            continue;
            
        answer.push_back(result);
    }

    return answer;
}

#include <iostream>

void print(vector<string> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
  cout << endl;
}

int main()
{
  print(solution( {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan"} ));
  // Prodo님이 들어왔습니다. Ryan님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다.    

  return 0;
}