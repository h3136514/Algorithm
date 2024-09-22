#include <vector>
#include <algorithm>

using namespace std;
int money[4] ={100, 50, 10, 1}; // 화폐 단위를 큰 순서대로

vector<int> solution(int amount) {
    vector<int> change; // 거스름돈을 담을 벡터
    
    for(int i = 0; i < 4; i++) {
        while(amount >= money[i]) {
            change.push_back(money[i]);
            amount -= money[i];
        }
    }
  
    return change; // 거스름돈 반환
}


// 테스트 코드
#include <iostream>


void print(vector<int> vec)
{
    cout << vec[0];
    for(int i = 1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}


int main()
{
    print(solution(123)); //출력값 : 100 10 10 1 1 1
    print(solution(350)); //출력값 : 100 100 100 50
  
    return 0;
}