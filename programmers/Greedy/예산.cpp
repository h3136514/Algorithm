#include <vector>
#include <algorithm>

using namespace std;
int cnt;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    cnt = 0;
    for(int i = 0; i < d.size(); i++) {
        if(budget < d[i])   // 남은 예산이 신청한 금액보다 작으면 더 이상 지원할 수 없으므로 종료
            break;
        
        cnt++;
        budget -= d[i];
    }
    
    return cnt;
}


// 테스트 코드
#include <iostream>

int main()
{
  cout << solution({1, 3, 2, 5, 4}, 9) << endl; //출력값 : 3
  cout << solution({2, 2, 3, 3}, 10) << endl; //출력값 : 4
  
  return 0;
}
