#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    
    // 숫자를 문자열로 변환
    string s = to_string(n);
    
    // 역순으로 정렬
    sort(s.rbegin(), s.rend());
    
    // 문자열을 숫자로 변환
    long long answer = stoll(s);
    
    return answer;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(118372) << endl; // 출력값 : 873211

  return 0;
}