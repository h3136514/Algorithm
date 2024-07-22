#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> orderCombi; // 주문의 조합 - 조합의 빈도

// 실제 주문의 조합을 구하는 함수
void combination(string src, string dst, int depth) {
  if (dst.size() == depth)
      orderCombi[dst]++;

  else 
      for (int i = 0; i < src.size(); i++)
          combination(src.substr(i+1), dst+src[i], depth);
}

// 단품메뉴들의 갯수에 맞게 가장 많이 함께 주문된 단품메뉴 조합의 코스요리 메뉴 구성 문자열을 반환(orders의 길이: N, course의 길이: M, 시간복잡도 : O(M*2^N))
vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  //각 주문들을 오름차순으로 정렬
  for (string &order : orders)
    sort(order.begin(), order.end());
  
  for (int len : course) {
    for (string order : orders)
      // course의 길이에 해당되는 조합 생성
      combination(order, "", len);

    // 각 주문의 빈도수를 순회하면서 가장 많은 빈도수를 maxOrder에 저장
    int maxOrder = 0;
    for (auto it : orderCombi)
      maxOrder = max(maxOrder, it.second);

    // 주문 횟수가 2회 이상이면서, 가장 많이 주문된 주문의 구성은 answer에 추가
    for (auto it : orderCombi)
      if (maxOrder >= 2 && it.second == maxOrder)
        answer.push_back(it.first);
    
    orderCombi.clear();     //코스별 조합 초기화
  }
    
  // 주문의 구성들을 오름차순 정렬 
  sort(answer.begin(), answer.end());
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
    print(solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4})); //출력값 :  AC ACDE BCFG CDE
    print(solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5})); //출력값 : ACD AD ADE CD XYZ
    print(solution({"XYZ", "XWY", "WXA"}, {2, 3, 4})); //출력값 : WX XY 

    return 0;
}