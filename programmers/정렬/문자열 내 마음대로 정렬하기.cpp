#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;

// 비교 함수
bool compare(string a, string b) {
    return a[N] == b[N] ? a < b : a[N] < b[N];
} 

vector<string> solution(vector<string> strings, int n) {
    N = n;
    
    // 각 문자열의 N 번째 문자를 기준으로 정렬 
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}


#include <iostream>

using namespace std;

void print(vector<string> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
  print(solution({"sun", "bed", "car"}, 1)); //출력값 : car bed sun
  print(solution({"abce", "abcd", "cdx"}, 2));  // 출력값 : abcd abce cdx

  return 0;
}