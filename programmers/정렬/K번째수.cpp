#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        int s = commands[i][0] - 1;
        int e = commands[i][1] - 1;
        int k = commands[i][2];
        
        //해당되는 영역만 삽입
        vector<int> v;
        for(int j = s; j <= e; j++) {
            v.push_back(array[j]);
        }
        
        // 정렬
        sort(v.begin(), v.end());
        
        // k번째 answer에 추가
        answer.push_back(v[k-1]);
    }
    
    return answer;
}


#include <iostream>

using namespace std;

void print(vector<int> vec)
{
 for(int i = 0; i < vec.size(); i++)
    cout << vec[i] << " ";
  cout << "\n";
}

int main()
{
  print(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}})); // 출력값 : 5 6 3

  return 0;
}

//간단한 코드
/*
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  vector<int> subArray;

  for (const auto& cmd : commands) {
    // array에서 각 cmd에 해당되는 영역만 subArray로 복사후 정렬
    subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
    sort(subArray.begin(), subArray.end());
      
    // subArray에서 k번 째 answer에 추가
    answer.push_back(subArray[cmd[2] - 1]);     
  }

  return answer;
}



*/