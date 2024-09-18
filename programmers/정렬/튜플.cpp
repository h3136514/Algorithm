#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
stack<int> st;
vector<int> tmp;
priority_queue<pair<int, vector<int>>> q;
bool check; // 집합의 원소 안이지 체크
int visitied[100001]; //원소의 튜플 포함 유무

vector<int> solution(string s) {
    vector<int> answer;
    
    string str = "";
    for(int i = 1; i < s.size() - 1; i++) {
        // 다른 원소
        if(!check && s[i] == ',') {
            tmp.clear();
            continue;
        }
        // 같은 원소
        if(check && s[i] == ',') {
            st.push(stoi(str));
            str = "";
            continue;
        }
        if(s[i] == '{') {
            check = true;
            continue;
        }
        if(s[i] == '}') {
            st.push(stoi(str));
            int cnt = st.size();
            
            while(!st.empty()) {
                tmp.push_back(st.top());
                st.pop();
            }
            check = false;
            //원소 갯수 및 원소 우선순위 큐에 삽입
            q.push({-cnt, tmp});
            
            str = "";
            
            continue;
        }
        
        str += s[i];
    }
    
    
    while(!q.empty()) {
        vector<int> v = q.top().second;
        q.pop();
        
        // 집합의 원소 순서대로 탐색 및 삽입
        for(int num : v){
            if(!visitied[num]) {
                visitied[num] = 1;
                answer.push_back(num);      
            }
        }
    }
    
    return answer;
}


#include <iostream>

using namespace std;

void init()
{
    tmp.clear();
    for(int i = 0 ; i <= 100000; i++)
        visitied[i] = 0;    
}

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
  print(solution("{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}")); // 출력값 : 2 1 3 4
  init();
  print(solution("{{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}")); // 출력값 : 2 1 3 4
  init();
  print(solution("{{20, 111}, {111}}")); // 출력값 : 111 20
  init();
  print(solution("{{123}}")); // 출력값 : 123
  init();
  print(solution("{{4, 2, 3}, {3}, {2, 3, 4, 1}, {2, 3}}")); // 출력값 : 3 2 4 1 
  
  return 0;
}


// 더 간결한 코드
/*

int counts[100001] = {};

void updateCounts(const string& s) {
  string numStr;
  // 인자로 받은 문자열을 순회
  for (char ch : s) {
    // 현재 문자가 숫자인 경우
    if (isdigit(ch)) {
      numStr += ch;
    // 현재 문자가 숫자가 아닌 경우
    } else {
      if (!numStr.empty()) {    // 문자가 ","이거나 "}"일 때
        // 계수정렬을 하기 위해 각 숫자의 개수를 저장 
        counts[stoi(numStr)]++;
        numStr.clear();
      }
    }
  }
}

vector<int> solution(string s) {
  vector<int> answer;
  // 집합이 담긴 문자열의 각 원소를 계수정렬
  updateCounts(s);

  vector<pair<int, int>> freqPairs;
  for (int i = 1; i <= 100000; i++) {
    // 집합에 있는 원소인 경우 (개수, 값) 형식으로 푸시
    if (counts[i] > 0) {
      freqPairs.push_back({counts[i], i});
    }
  }

  // 각 원소의 개수를 기준으로 내림차순 정렬
  sort(freqPairs.rbegin(), freqPairs.rend());

  // 원소의 개수로 내림차순 정렬된 벡터를 순회하며 원소를 푸시
  for (const auto& p : freqPairs) {
    answer.push_back(p.second);
  }

  return answer;
}

*/