#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
int a, b;
string word;
unordered_map<string, int> map;

// 사람의 수 n과 사람들이 순서대로 말한 단어 words 가 매개변수로 주어질 때, 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 반환(시간복잡도 : O(N))
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    // 한 글자인 단어를 처음부터 말했을 때
    if(words[0].size() == 1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }else
        map.insert({words[0], 1});
    
    
    for(int i = 1; i < words.size(); i++){
        word = words[i-1];  //방근전에 언급한 단어
        //이전에 등장했거나 앞사람이 말한 단어의 마지막 문자로 시작하지 않거나 한 글자인 단어일 때 탈락
        if(map.count(words[i]) || words[i][0] != word[word.size() - 1] || words[i].size() == 1){
            answer.push_back(i%n + 1);  // 번호
            answer.push_back(i/n + 1);  // 차례
            return answer;
        }
        map.insert({words[i], 1});
    }
    // 탈락자가 생기지 않을 때
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}

#include <iostream>

void print(vector<int> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << ", " << vec[i];
    }
  cout << endl;
}

int main()
{
  print(solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})); // 결과값 : 3 3
  print(solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})); // 결과값 : 0 0
  print(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"})); // 결과값 : 1 3
  
  return 0;
}

// set을 활용한 풀이(map 사용X, usedWords.insert(words[i]).second의 값(false, true)을 보고 중복 확인)
/*
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
  vector<int> answer(2, 0);
  unordered_set<string> usedWords;
    
  usedWords.insert(words[0]);

  //두 번째 단어부터 끝까지 반복
  for (int i = 1; i < words.size(); ++i) {
    //단어가 이미 사용되었거나, 끝말잇기 규칙에 맞지 않는 경우
    if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
      //플레이어 번호와 턴 번호 저장 후 바로 반환
      answer[0] = i % n + 1;
      answer[1] = i / n + 1;
      return answer;
    }
  }

  //중간에 탈락하는 플레이어가 없으면 [0, 0] 반환
  return answer;
}
*/