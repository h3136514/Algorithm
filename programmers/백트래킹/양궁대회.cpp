#include <string>
#include <vector>

using namespace std;
vector<int> ryan(11,0), peach, result;
int differMax = -1;

// score: 현재 확인하려고 하는 점수, cnt: 남은 화살의 갯수
void dfs(int score, int cnt) {
    if(score == -1 || cnt == 0) {
        int peachSum = 0, ryanSum = 0;
        
        ryan[10] = cnt;
        // 점수 계산
        for(int i = 0; i < 11; i++) {
            if(peach[i] < ryan[i]) {
                ryanSum += 10-i;
            }else if(peach[i] > ryan[i]) {
                peachSum += 10-i;
            }else if(peach[i] != 0) {
                peachSum += 10-i;
            }
        }
        // 점수 차이
        int differ = ryanSum - peachSum;
        
        //최대 점수로 이기는 경우만(중복도 체크)
        if(differ > 0 && differMax <= differ){
            // 점수 갱신(더 최소 점수일 때)
            if(differMax == differ) {
                // 라이언 점수 비교(가장 낮은 점수를 더 많이 맞힌 경우 찾기)
                for(int i = 10; i >= 0; i--) {
                    if(result[i] == ryan[i]){
                        continue;   
                    }

                    if(result[i] < ryan[i]){
                        result = ryan;
                    }

                    break;
                }
            }else {
                differMax = differ; //최대 점수 갱신
                result = ryan;  
            }

        }
        ryan[10] = 0;
        
        return;
        
    }
    
    // 어피치보다 쏠 화살이 남은 경우
    if(peach[score] < cnt) {
        ryan[score] = peach[score] + 1;
        dfs(score - 1, cnt - (peach[score] + 1));
        ryan[score] = 0;
    }
    // 화살을 안 쏜 경우
    dfs(score - 1, cnt);
    
}

vector<int> solution(int n, vector<int> info) {
    peach = info;

    dfs(10, n);
        
    if(differMax == -1) {
        return {-1};
    }
    
    return result;  
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

void init(){
  result.clear();
  differMax = -1;
  
  for(int i = 0 ; i < ryan.size(); i++) {
    ryan[i] = 0;
  }
   
}

void print(vector<int> vec)
{
    cout << vec[0];
    for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

int main()
{
  print(solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0})); //출력값 : 0 2 2 0 1 0 0 0 0 0 0 
  init();
  print(solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})); //출력값 : -1
  init();
  print(solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1})); //출력값 : 1 1 2 0 1 2 2 0 0 0 0 
  return 0;
}