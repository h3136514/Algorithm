#include <iostream>

using namespace std;
int cnt;

int solution(int n)
{  
    cnt = 0;
    while(n > 0) {
        if(n % 2 == 0){
           n /= 2;
           continue;
        }
       
        n -= 1;
        cnt++;
    }

    return cnt;
}

// 테스트 코드


int main()
{
    cout << solution(5) << endl; //출력값 : 2
    cout << solution(6) << endl; //출력값 : 2 
    cout << solution(5000) << endl; //출력값 : 5
  
  return 0;
}

// 더 간결한 코드(bitset 이용)
/*
#include <bitset>


int solution(int N) {
  return bitset<32>(N).count(); // 2진수로 변환한 N의 1의 개수를 반환
}

*/