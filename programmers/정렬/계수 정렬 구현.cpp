#include <string>
#include <vector>

using namespace std;
vector<int> counts(26, 0);     //알파벳 개수(26개)만큼 빈도수 배열 생성
string str;

void init() {
    str = "";
    for(int i = 0; i < 26; i++)
        counts[i] = 0;
}

string solution(string s) {
    init();

    for(char c : s)
        counts[c -'a']++;
    
    for(int i = 0; i < 26; i++)
        str += string(counts[i], i + 'a');

    return str;
}


#include <iostream>


int main()
{
  cout << solution("hello") << endl; // 출력값 : ehllo
  cout << solution("algorithm") << endl; // 출력값 : aghilmort
  
  return 0;
}