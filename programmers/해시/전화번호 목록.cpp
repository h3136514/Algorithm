#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 전화번호부를 저장하기 위한 해시맵
unordered_map<string, int> phoneBook;

// 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인 (시간복잡도 : O(N))
bool solution(vector<string> phone_book) {
    // 전화번호부를 해시맵에 저장
    for(int i = 0; i < phone_book.size(); i++)
        phoneBook[phone_book[i]] =1;
    
    //각 전화번호가 접두어가 있는지 확인
    for(int i = 0; i < phone_book.size(); i++){
        string prefix = "";
        for(char c : phone_book[i]){
            prefix += c;
            //현재 접두어가 전화번호부에 있고 현재 번호와 같지 않으면 = 접두어
            if(phoneBook.find(prefix) != phoneBook.end() && prefix != phone_book[i])
                return false;
        }
    }
    
    return true;
}

#include <iostream>

int main()
{
  //bool 반환할 때 true는 1, false는 0 입니다.
  cout << solution({"119", "97674223", "1195524421"}) << endl; //출력값 : 0
  cout << solution({"123", "456", "789"}) << endl; //출력값 : 1
  cout << solution({"12", "123", "1235", "567", "88"}) << endl; //출력값 : 0
  
  return 0;
}

//정렬을 활용한 풀이(map 사용X, 시간복잡도 : O(NlogN))
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phoneBook) {
  //전화번호 목록을 오름차순으로 정렬
  sort(phoneBook.begin(), phoneBook.end());

  //모든 전화번호를 순회하면서 다음 번호와 비교
  for (int i = 0; i < phoneBook.size() - 1; ++i) {
    //현재 번호가 다음 번호의 접두어인 경우 false 반환
    if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
      return false;
    }
  }

  //어떤 번호도 다른 번호의 접두어가 아닌 경우 true 반환
  return true;
}
*/