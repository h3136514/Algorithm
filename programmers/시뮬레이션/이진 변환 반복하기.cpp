#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<char> st;
int cnt, zero_cnt;

vector<int> solution(string s) {
    vector<int> answer;
    string str = s;
    while(true){
        if(str == "1")
            break;
        
        string one_str = "";    // 0이 제거된 문자열
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0') {
                zero_cnt++; //0제거 횟수 증가
                continue;
            }
            one_str += str[i];
        }
        
        // (0이 제거된)문자열 길이를 2진법으로 변환
        int size = one_str.size();
        while(size > 0) {
            if(size % 2 == 0) {
                st.push('0');
                size /= 2;
            }else {
                st.push('1');
                size -= 1;
                size /= 2;
            }
        }
        
        // 2진법으로 변환 문자열 삽입
        string trans_str = "";
        while(!st.empty()) {
            trans_str += st.top();
            st.pop();
        }
        
        cnt++;  // 2진 변환 횟수 증가
        str = trans_str;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    
    return answer;
}


//테스트 코드
#include <iostream>

using namespace std;

void init() {
    cnt = 0;
    zero_cnt = 0;
}

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

int main()
{
  print(solution("110010101001")); //출력값 : 3 8
  init();
  print(solution("01110")); //출력값 : 3 3
  init();
  print(solution("1111111")); //출력값 : 4 1
  
  return 0;
}

// 더 간결한 코드(bitset 이용)
/*
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
  int transforms = 0;
  int removedZeros = 0;

  //  s가 “1”이 될때까지 계속 반복
  while (s != "1") {
    transforms++;

    // '0' 개수를 세어 removedZeros에 누적
    removedZeros += count(s.begin(), s.end(), '0');

    // '1' 개수를 세고, 이를 이진수로 변환
    int onesCount = count(s.begin(), s.end(), '1');
    // 2진법 변환
    s = bitset<32>(onesCount).to_string();
    s = s.substr(s.find('1'));
  }

  return {transforms, removedZeros};
}


*/