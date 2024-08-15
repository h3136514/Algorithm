#include <vector>

using namespace std;
vector<vector<int>> results;
vector<int> num;

void backtrack(int n, int sum, int start) {
    // 합이 10인경우, 조합을 결과에 추가하고 종료
    if(sum == 10) {
        results.push_back(num);
        return;
    }

    for(int i = start; i <= n; i++) {
        // 가능한 조합을 계속 확인
        if(sum+i <= 10) {
            num.push_back(i);
            backtrack(n, sum+i, i+1);
            num.pop_back();
        }
    }
    
}

// 정수 N을 입력받아 1부터 N까지의 숫자 중에서 합이 10되는 조합을 배열로 반환(시간복잡도 : O(N!), 다만 실제 연산은 유망함수에 의해 훨씬 적다.)
vector<vector<int>> solution(int N) {
  // 숫자 1부터 백트래킹 시작
  backtrack(N, 0, 1);
  return results;
}


#include <iostream>

void init()
{
  results.clear();
  num.clear();    
}

void print(vector<vector<int>> vecs)
{
    for(vector<int> vec : vecs) {
        cout << vec[0];
        for(int i =1; i < vec.size(); i++){
            cout << " " << vec[i];
        }
        cout << endl;
    }
}

int main()
{
  print(solution(5));
  init();
  /*
    출력값
    1 2 3 4 
    1 4 5 
    2 3 5 
  */
  print(solution(2));
  init();
  /*
    출력값(없음)
  */  
  print(solution(7));
  /*
    출력값
    1 2 3 4 
    1 2 7 
    1 3 6 
    1 4 5 
    2 3 5 
    3 7 
    4 6 
  */
  return 0;
}

