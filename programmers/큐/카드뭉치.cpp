#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<string> q1, q2;

//cards1과 cards2에 적힌 단어들로 앞에서부터 순서대로 goal를 만들 수 있다면 "Yes"를, 만들 수 없다면 "No"를 반환 (cards1+cards2길이: N,  goal길이: M, 시간복잡도 : O(N+M))
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    //문자열 큐에 삽입
    for(int i = 0; i < cards1.size(); i++)
        q1.push(cards1[i]);
    for(int i = 0; i < cards2.size(); i++)
        q2.push(cards2[i]);
    
    for(int i = 0; i < goal.size(); i++){
        //q1의 현재 문자열과 일치하는 경우
        if(!q1.empty() && goal[i].compare(q1.front()) == 0){
            q1.pop();
            continue;   
        }
        //q2의 현재 문자열과 일치하는 경우
        if(!q2.empty() && goal[i].compare(q2.front()) == 0){
            q2.pop();
            continue;   
        }
        //일치하는 카드뭉치가 없는 경우 "No"반환
        return "No";
    }
     //원하는 문자열을 카드뭉치에서 만들었으므로 "Yes"반환
    return "Yes";
}

#include <iostream>

int main()
{
    cout<< solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "Yes"
    cout<< solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"}) << endl; // "No"
    return 0;

}

//queue를 사용하지 않고 구현
/*
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
  int l = 0;
  int r = 0;

  for (string& g: goal) {
    if (g == cards1[l]) {
      l++;
    } else if (g == cards2[r]) {
      r++;
    } else {
      return "No";
    }
  }

  return "Yes";
}
*/