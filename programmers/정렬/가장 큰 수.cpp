#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> strings;

//  두 수를 조합해서 크기를 비교
bool compare(string a, string b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    strings.clear();
    string answer = "";

    //  원소를 문자열로 변형해서 푸시
    for(int i = 0; i < numbers.size(); i++) 
        strings.push_back(to_string(numbers[i]));
       
    sort(strings.begin(), strings.end(), compare);

    // 정렬함수를 기준으로 정렬 
    for(int i = 0; i < strings.size(); i++)
        answer += strings[i];
    
    return answer[0] == '0' ? "0" : answer;
}


#include <iostream>


int main()
{
  cout << solution({6, 10, 2}) << endl; // 출력값 : 6210
  cout << solution({3, 30, 34, 5, 9}) << endl; // 출력값 : 9534330
  return 0;
}
