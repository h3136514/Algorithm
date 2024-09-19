#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s1 ,s2;
int cnt, left, right, num[10001];

int solution(vector<int> topping) {
    // 토핑 갯수 세기
    for(int i = 0; i < topping.size(); i++) {
        s2.insert(topping[i]);
        num[topping[i]]++;
    }
    
    left = 0;
    right = 1;
    //왼쪽 => 오른쪽 끝까지 가면서 공평하게 나누어지는지 확인(앞에서 부터 토핑을 순서대로 순회)
    while(right < topping.size()) {
        int target = topping[left++];
        
        s1.insert(target);
        num[target]--;
        //해당 토밍이 뒤에 없으므로 삭제
        if(!num[target])
            s2.erase(target);
        
        // 토핑 수 가 같으므로
        if(s1.size() == s2.size())
            cnt++;
        
        right++;
    }
    
    return cnt;
}

//테스트 코드
#include <iostream>

void init() {
    cnt = 0;
    for(int i = 0; i <10001; i++)
        num[i] = 0;

    s1.clear();
    s2.clear();
}

int main()
{
  cout << solution({1, 2, 1, 3, 1, 4, 1, 2}) << endl; // 출력값 : 2
  init();
  cout << solution({1, 2, 3, 1, 4}) << endl; // 출력값 : 0
  
  return 0;
}

// unordered_map을 이용
/*

#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;

  // 남아있는 각 토핑의 개수
  unordered_map<int, int> topping_cnt;
  // 절반에 속한 토핑의 종류
  unordered_set<int> half_topping;

  // 카운터에 각 토핑의 개수를 저장
  for (auto top : topping) {
    if (topping_cnt.find(top) == topping_cnt.end()) {
      topping_cnt[top] = 1;
    } else {
      topping_cnt[top]++;
    }
  }

  // 앞에서 부터 토핑을 순서대로 순회
  for (int i = 0; i < topping.size(); i++) {
    // 절반에 속하는 토핑에 추가하고, 남은 토핑개수에서 제외
    half_topping.insert(topping[i]);
    topping_cnt[topping[i]]--;
     // 현재 토핑이 남아있지 않은 경우 남은 토핑 목록에서 삭제
    if (topping_cnt[topping[i]] == 0) {
      topping_cnt.erase(topping[i]);
    }
    // 공평한 경우 카운팅
    if (topping_cnt.size() == half_topping.size()) {
      answer++;
    }
  }

  return answer;
}

*/